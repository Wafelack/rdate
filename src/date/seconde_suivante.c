#include <date.h>

void
seconde_suivante (self)
  struct date *self;
{
  if (self->seconde >= 99)
    {
      self->seconde = 0;
      minute_suivante (self);
    }
  else
    self->seconde++;
}
