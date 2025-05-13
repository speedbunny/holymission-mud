inherit "obj/bag";
#include "../harbour.h"

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("bag");

    set_short("fishing bag");
    set_long("It's a normal bag. You can put things in it\n");

    set_value(50);
    set_weight(1);
    CO("fish");
    CO("fish");
    CO("fish");
    CO("fish");
    CO("fish");
  }
}
