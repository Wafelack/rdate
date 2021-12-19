#include <date/date.h>
#include <format/format.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define DEFAULT_FORMAT ("%a %d %b %H:%M:%S %y")
#define PROGRAM_NAME ("rdate")

int
main(argc, argv)
  int argc;
  char * const argv[];
{
  time_t now;
  struct date d;
  char date[1024] = {0};

  now = time (NULL);
  d = depuis_secondes (now);
  
  if (argc == 1)
    datef (&d, DEFAULT_FORMAT, date);
  else if (argc == 2)
    datef (&d, argv[1], date);
  else
    {
      fprintf (stderr, "%s : opérande surnuméraire : « %s »", PROGRAM_NAME, argv[2]);
      return EXIT_FAILURE;
    }

  puts (date);
  return 0;
}
