#ifndef _FORMAT_FORMAT_H
# define _FORMAT_FORMAT_H 1

# include <date.h>
# include <stdint.h>
# define PUSH(b, c) (*(b++) = c)

void  datef (struct date *, const char *, char []);
void  vers_romains (uint64_t, char []);

#endif /* _FORMAT_FORMAT_H */
