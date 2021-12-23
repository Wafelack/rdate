#include <date.h>
#include <format.h>
#include <jour.h>
#include <stdio.h>
#include <string.h>

void
datef (date, fmt, buf)
  struct date   *date;
  const char    *fmt;
  char          buf[];
{
  size_t longueur, i = 0;

  longueur = strlen (fmt);
  for (; i < longueur; i++)
    {
      char c = fmt[i];

      if (c != '%')
        PUSH(buf, c);
      else
        {
          c = fmt[++i];

          switch (c)
            {
            case 'N':
              strcpy (buf, nom_unique_jour (date));
              buf += strlen (buf);
              break;
            case 'a':
            case 'b':
              {
                char nom[50];
                
                if (c == 'a')
                  nom_jour (date, nom);
                else
                  nom_mois (date, nom);
                PUSH(buf, nom[0]);
                PUSH(buf, nom[1]);
                PUSH(buf, nom[2]);
                break;
              }
            case 'A':
            case 'B':
              {
                char nom[50];
                
                if (c == 'A')
                  nom_jour (date, nom);
                else
                  nom_mois (date, nom);
                strcpy (buf, nom);
                buf += strlen (nom);
                break;
              }
            case 'c':
              datef (date, "%a %d %b %H:%M:%S %Y", buf);
              buf += strlen (buf);
              break;
            case 'C':
              sprintf (buf, "%d", date->an / 100);
              buf += strlen (buf);
              break;
            case 'd':
              sprintf (buf, "%02d", date->jour);
              buf += strlen (buf);
              break;
            case 'D':
              datef (date, "%m/%d/%y", buf);
              buf += strlen (buf);
              break;
            case 'F':
              datef (date, "%Y-%m-%d", buf);
              buf += strlen (buf);
              break;
            case 'H':
              sprintf (buf, "%02d", date->heure);
              buf += strlen (buf);
              break;
            case 'j':
              sprintf (buf, "%03d", date->mois * 30 + date->jour);
              buf += strlen (buf);
              break;
            case 'm':
              sprintf (buf, "%02d", date->mois + 1);
              buf += strlen (buf);
              break;
            case 'M':
              sprintf (buf, "%02d", date->minute);
              buf += strlen (buf);
              break;
            case 'n':
              PUSH(buf, '\n');
              break;
            case 'q':
              {
                uint8_t v;

                if (date->mois < 3)
                  v = 1;
                else if (date->mois < 6)
                  v = 2;
                else if (date->mois < 9)
                  v = 3;
                else
                  v = 4;
                PUSH(buf, '0' + (char)v);
                break;
              }
            case 'R':
              datef (date, "%H:%M", buf);
              buf += strlen (buf);
              break;
            case 'S':
              sprintf (buf, "%02d", date->seconde);
              buf += strlen (buf);
              break;
            case 't':
              PUSH(buf, '\t');
              break;
            case 'T':
              datef (date, "%H:%M:%S", buf);
              buf += strlen (buf);
              break;
            case 'u':
            case 'w':
              sprintf (buf, "%02d", date->jour + (c == 'u' ? 1 : 0));
              buf += strlen (buf);
              break;
            case 'y':
              sprintf (buf, "%d", date->an);
              buf += strlen (buf);
              break;
            case 'Y':
              PUSH(buf, 'A');
              PUSH(buf, 'n');
              PUSH(buf, ' ');
              vers_romains (date->an, buf);
              buf += strlen (buf);
              break;
            default:
              PUSH(buf, c);
              break;
            }
        }
    }
}
