#include <date.h>

void
minute_suivante (self)
  struct date *self;
{
  if (self->minute >= 59)
    {
      self->minute = 0;
      heure_suivante (self);
    }
  else
    self->minute++;
}
