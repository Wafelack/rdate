#ifndef _DATE_DATE_H
# define _DATE_DATE_H 1

# include <stdbool.h>
# include <stdint.h>

# define MOIS (13)
# define SPJ (10 * SPH)
# define SPH (100 * SPM)
# define SPM (100)

enum mois 
{
  VENDEMIAIRE = 0,
  BRUMAIRE = 1,
  FRIMAIRE = 2,
  NIVOSE = 3,
  PLUVIOSE = 4,
  VENTOSE = 5,
  GERMINAL = 6,
  FLOREAL = 7,
  PRAIRIAL = 8,
  MESSIDOR = 9,
  THERMIDOR = 10,
  FRUCTIDOR = 11,
  SANCULOTTIDES = 12
};

struct date
{
  uint8_t   jour;
  enum mois mois;
  uint32_t  an;
  uint8_t   heure;
  uint8_t   minute;
  uint8_t   seconde;
  bool      sextile;
};

struct date   date_par_defaut (void);
struct date   depuis_secondes (uint64_t);

uint64_t      proceder_an (struct date *, uint64_t);
uint64_t      proceder_mois (struct date *, uint64_t);
uint64_t      proceder_jour (struct date *, uint64_t);
uint64_t      proceder_heure (struct date *, uint64_t);
uint64_t      proceder_minute (struct date *, uint64_t);

void          annee_suivante (struct date *);
void          mois_suivant (struct date *);
void          jour_suivant (struct date *);
void          heure_suivante (struct date *);
void          minute_suivante (struct date *);
void          seconde_suivante (struct date *);

void          nom_mois (struct date *, char *);
void          nom_jour (struct date *, char *);

#endif /* _DATE_DATE_H */
