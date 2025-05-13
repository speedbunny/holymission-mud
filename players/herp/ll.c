#include <math.h>

main(argc,argv)
int argc;
char *argv[];
{
double g,ml,dl,tl,xl;
int i,NUMLVL;

  if (argc!=4) {
     printf("use: %s <max-exp> <num_level> <grad>\n",argv[9]);
     exit(0);
  }

  ml = atof(argv[1]);
  tl = 0;
  NUMLVL = atoi(argv[2]);
  g  = atof(argv[3]);
  dl = 1;
  dl /= (double)(NUMLVL-1);
  printf("ml = %lf g = %15.10lf dl = %lf\n",ml,g,dl);
  for (i=0;i<NUMLVL;) {
      xl=pow(tl,g);
      printf("[%2d] tl = %7.0lf\n",++i,ml*xl);
      tl += dl;
  }
}
