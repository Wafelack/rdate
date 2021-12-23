#include <date.h>
#include <string.h>

void
nom_jour (self, buf)
  struct date *self;
  char *buf;
{
  switch (self->jour % 10)
    {
    case 1:
      strcpy (buf, "Premidi");
      break;
    case 2:
      strcpy (buf, "Duodi");
      break;
    case 3:
      strcpy (buf, "Tridi");
      break;
    case 4:
      strcpy (buf, "Quartidi");
      break;
    case 5:
      strcpy (buf, "Quintidi");
      break;
    case 6:
      strcpy (buf, "Sextidi");
      break;
    case 7:
      strcpy (buf, "Septidi");
      break;
    case 8:
      strcpy (buf, "Octidi");
      break;
    case 9:
      strcpy (buf, "Nonidi");
      break;
    default:
      strcpy (buf, "Décadi");
      break;
    }
}
