inherit "obj/weapon";
#include "/players/meecham/def.h"
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("hammer");
  set_class(19);
  set_weight(9);
  set_value(5000);
  set_short("hammer");
  set_long("You see a fine priest's hammer.");
}
 
 
