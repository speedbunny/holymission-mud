#include "/players/sauron/include/include.h"

void test(int hits) {
  int low,high,av,tot,tmp,i;
  mapping map;

  map=([]);
  for(i=1;i<=10;i++)
    map[i]=0;
  for(i=0;i<hits;i++) {
    tmp=(gausian(4,49,0,5)/5)+1;
//    printf("%d%s",tmp,((i+1)%10?", ":"\n"));
    if(!low)
      low=tmp;
    else if(tmp<low)
      low=tmp;
    if(!high)
      high=tmp;
    else if(tmp>high)
      high=tmp;
    tot+=tmp;
    map[tmp]++;
  }
  av=tot/hits;
  printf("Test for %d hits:\nAverage = %d, Low = %d, High = %d\nHits: ",
         hits,av,low,high);
  for(i=1;i<=10;i++)
    printf("%d: %d%s",i,map[i],(i==10?"\n":", "));
}
