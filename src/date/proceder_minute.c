#include <date/date.h>

uint64_t
proceder_minute (self, s)
  struct date *self;
  uint64_t s;
{
  if (s >= SPM)
    {
      minute_suivante (self);
      s -= SPM;
    }
  return s;
}
