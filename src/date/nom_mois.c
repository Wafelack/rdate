#include <date.h>
#include <string.h>

void
nom_mois (self, buf)
  struct date *self;
  char *buf;
{
  switch (self->mois)
    {
    case VENDEMIAIRE:
      strcpy (buf, "Vendémiaire");
      break;
    case BRUMAIRE:
      strcpy (buf, "Brumaire");
      break;
    case FRIMAIRE:
      strcpy (buf, "Frimaire");
      break;
    case NIVOSE:
      strcpy (buf, "Nivôse");
      break;
    case PLUVIOSE:
      strcpy (buf, "Pluviôse");
      break;
    case VENTOSE:
      strcpy (buf, "Ventôse");
      break;
    case GERMINAL:
      strcpy (buf, "Germinal");
      break;
    case FLOREAL:
      strcpy (buf, "Floréal");
      break;
    case PRAIRIAL:
      strcpy (buf, "Prairial");
      break;
    case MESSIDOR:
      strcpy (buf, "Messidor");
      break;
    case THERMIDOR:
      strcpy (buf, "Thermidor");
      break;
    case FRUCTIDOR:
      strcpy (buf, "Fructidor");
      break;
    case SANCULOTTIDES:
      strcpy (buf, "Sanculottides");
      break;
    default: break;
    }
}
