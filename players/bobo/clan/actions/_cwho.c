
#include "/players/bobo/clan/defines.h"

int _cwho(string arg, object *amulet){
  string *list, l;
  int i;

  l = "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";

    
   printf("%s48.48s\n%s\n", 1, "Sun Cult of Ra", 1);
  list = SERVER->get_clan();

  for(i = 0; i < sizeof(list); i++)
    printf("%s\n", list[i]);
  
  printf("%s\n", l);
  return 1;
}


