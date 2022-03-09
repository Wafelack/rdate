#include <date.h>

void
heure_suivante (self)
  struct date *self;
{
  if (self->heure >= 9)
    {
      self->heure = 0;
      jour_suivant (self);
    }
  else
    self->heure++;
}
