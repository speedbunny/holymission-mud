
#include "/players/wilbie/clan/defines.h"

int _cwho(string arg, object *pendant){
  string *list, l;
  int i;

  l = "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";

    
  printf("%s\n%48.48s\n%s\n", l, "Cult of The Dark Moon", l);
  list = SERVER->get_clan();

  for(i = 0; i < sizeof(list); i++)
    printf("%s\n", list[i]);
  
  printf("%s\n", l);
  return 1;
}


