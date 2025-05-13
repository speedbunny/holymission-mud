inherit "/obj/bag";
#include "../harbour.h"

reset(int arg)
{ ::reset(arg);
  if(arg) return 0;
  set_name("bag");
  set_alias("hunter's bag");
  set_short("hunter's bag");
  move_object(clone_object("/obj/money"),this_object());
  CO("fish");
  CO("roll");
}
