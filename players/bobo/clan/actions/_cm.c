
#include "/players/bobo/clan/defines.h"

int _cm(string arg, object *amulet) {
  string *list, l;
  int i;

  l = "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";

    
  printf("%s\n%48.48s\n%s\n", l, "Worshippers of the Sun", l);
  list = SERVER->get_clan();

  for(i = 0; i < sizeof(list); i++)
    printf("%s\n", list[i]);
  
  printf("%s\n", l);
  return 1;
}


