#include <format.h>

void
vers_romains (x, buf)
  uint64_t x;
  char buf[];
{
  while (x >= 1000)
    {
      PUSH(buf, 'M');
      x -= 1000;
    }
  if (x >= 900)
    {
      PUSH(buf, 'C');
      PUSH(buf, 'M');
      x -= 900;
    }
  if (x >= 500)
    {
      PUSH(buf, 'D');
      x -= 500;
    }
  if (x >= 400)
    {
      PUSH(buf, 'C');
      PUSH(buf, 'D');
      x -= 400;
    }
  while (x >= 100)
    {
      PUSH(buf, 'C');
      x -= 100;
    }
  if (x >= 90)
    {
      PUSH(buf, 'X');
      PUSH(buf, 'C');
      x -= 90;
    }
  if (x >= 50)
    {
      PUSH(buf, 'L');
      x -= 50;
    }
  if (x >= 40)
    {
      PUSH(buf, 'X');
      PUSH(buf, 'L');
      x -= 40;
    }
  while (x >= 10)
    {
      PUSH(buf, 'X');
      x -= 10;
    }
  if (x == 9)
    {
      PUSH(buf, 'I');
      PUSH(buf, 'X');
      x -= 9;
    }
  if (x >= 5)
    {
      PUSH(buf, 'V');
      x -= 5;
    }
  else if (x == 4)
    {
      PUSH(buf, 'I');
      PUSH(buf, 'V');
      x -= 4;
    }
  while (x > 0)
    {
      PUSH(buf, 'I');
      x -= 1;
    }
}
