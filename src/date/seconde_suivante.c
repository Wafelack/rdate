#include <date/date.h>

void
seconde_suivante (self)
  struct date *self;
{
  if (self->seconde >= 59)
    {
      self->seconde = 0;
      minute_suivante (self);
    }
  else
    self->seconde++;
}
