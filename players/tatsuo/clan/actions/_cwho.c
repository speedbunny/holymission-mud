
#include "/players/tatsuo/clan/defines.h"

int _cwho(string arg, object *hachimaka) {
  string *list, l;
  int i;

  l = "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";

    
  printf("%s\n%42.42s\n%s\n", l, "The Kokuryu Kai", l);
  list = SERVER->get_clan();

  for(i = 0; i < sizeof(list); i++)
    printf("%s\n", list[i]);
  
  printf("%s\n", l);
  return 1;
}


