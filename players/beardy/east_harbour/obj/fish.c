inherit "obj/food";
#include "../harbour.h"

reset(int arg)
{ ::reset(arg);
  if(arg) return 0;

  set_name("fish");

  set_short("a fish");
  set_long("It is a normal looking fish.\n");

  set_value(30);
  set_weight(1);

  eater_mess="You munch the fish.\n";
}

