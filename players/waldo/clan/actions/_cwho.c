
#include "/players/waldo/clan/defines.h"

int _cwho(string arg, object *hachimaka){
  string *list, l;
  int i;

  l = "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";

    
  printf("%s\n%48.48s\n%s\n", l, "House of Shimabuku", l);
  list = SERVER->get_clan();

  for(i = 0; i < sizeof(list); i++)
    printf("%s\n", list[i]);
  
  printf("%s\n", l);
  return 1;
}


