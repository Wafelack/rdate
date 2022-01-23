#include <convertir.h>
#include <date.h>
#include <format.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define FORMAT_DEFAUT ("%a %d %b (%N) %H:%M:%S %y")
#define FORMAT_DEFAUT_GREGORIEN ("%a %b %d %I:%M:%S %p %Z %Y")
#define NOM_PROGRAMME ("rdate")

int
main(argc, argv)
  int argc;
  char * const argv[];
{
  time_t maintenant;
  struct date d;
  int opt;

  char date[1024] = {0};

  const char *format = FORMAT_DEFAUT;
  const char *format_gregorien = FORMAT_DEFAUT_GREGORIEN;
  const char *date_gregorien = NULL;

  while (opt = getopt (argc, argv, "g:f:"), opt != -1)
    {
      switch (opt)
        {
        case 'g':
          date_gregorien = optarg;
          break;
        case 'f':
          format_gregorien = optarg;
          break;
        default:
          fprintf (stderr, "%s : usage: %s [-g dateg] [-f formatg]\n", NOM_PROGRAMME, argv[0]);
          return EXIT_FAILURE;
        }
    }

  if (argc == optind + 1)
    {
      format = argv[optind];
    }
  else if (argc > optind)
    {
      fprintf (stderr, "%s : opérande surnuméraire : « %s »", NOM_PROGRAMME, argv[optind]);
      return EXIT_FAILURE;
    }
  
  if (date_gregorien != NULL)
    {
      goto gregorien;
    }

  maintenant = time (NULL);
  d = depuis_secondes (maintenant);
  goto display;

gregorien:
  if (depuis_gregorien (date_gregorien, format_gregorien, &d) != 0)
    {
      fprintf (stderr, "%s: erreur de lecture de la date.", NOM_PROGRAMME);
      return EXIT_FAILURE;
    }

display:

  datef (&d, format, date);
  puts (date);

  return EXIT_SUCCESS;
}
