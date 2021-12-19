#include <date/date.h>

void
annee_suivante (self)
  struct date *self;
{
  self->an++;

  self->sextile = (self->an % 4 == 0 
      && (self->an % 100 != 0 
        || (self->an % 400 == 0 && self->an != 400)));
}
