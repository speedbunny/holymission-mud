#include "/players/saffrin/defs.h"
#define WIDTH 1

int main()
{
int i,j,k;
mixed u;

u=sort_array(users(),"level_desc",TO);
j=0;
write("\nMages currently on line\n----------------------\n");
for (i=0;i<sizeof(u);i++)
{
 if (u[i]->QGUILD == 5)
 {
  j++;
  k++;
/*
  write("[");
  write(u[i]->QLVL);
*/
  if (u[i]->QLVL > 29)
     write("Immortal ");
     else     
     write("Player ");
/*
  write("] ");
*/
  write(CAP(u[i]->QRNAM));
  if ( (k - ((k/WIDTH) * WIDTH)) == 0)
 write("\n");
     else
     write("\t");
  }
 }
write("\nThere are "+j+" mages on line.\n");
return 1;
}

level_desc(object a, object b)
{
  return (a->QLVL<=b->QLVL);
  }
