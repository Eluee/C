#include <stdio.h>

struct point
{
  int x, y;
};

int equel(struct point p1, struct point p2)
{
  if (p1.x == p2.x && p1.y == p2.y)
    return 1;
  else
    return 0;
}

int quadrant(struct point p)
{
  if (0 < p.x)
  {
    if (0 < p.y)
      return 1;
    else
      return 4;
  }
  else if (0 < p.y)
  {
    return 2;
  }
  else
  {
    return 3;
  }
}

int main(void)
{
  struct point p1 = {1, 2};
  struct point p2 = {1, 2};
  printf("%d", equel(p1, p2));
  return 0;
}