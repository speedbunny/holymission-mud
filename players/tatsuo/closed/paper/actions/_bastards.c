
#include "/players/tatsuo/closed/paper/defines.h"

int _bastards(string arg, object *credentials) {
  string *list, l;
  int i;

  l = "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";

  printf("%s\n%48.48s\n%s\n", l, "Complete Bastards Currently On Line", l);
  list = SERVER->get_paper();

  for(i = 0; i < sizeof(list); i++)
    printf("%s\n", list[i]);
    printf("%s\n", l);
  return 1;
}


