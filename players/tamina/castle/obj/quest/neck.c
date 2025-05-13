#include "/players/tamina/defs.h"

inherit "/obj/armour";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("silver necklace");
  set_alias("necklace");
  set_type("necklace");
  set_ac(0);
  set_weight(1);
  set_value(500);
  set_short("A silver necklace");
  set_long(
"A small, pretty silver necklace.  There is a little note\n"+
"engraved along the entwined cords of wrought silver itself...\n");
  set_read("...As light as light can be...\n");
}

int query_mage_wear()  { return 1; }
int query_monk_wear()  { return 1; }
int query_ninja_wear() { return 1; }

int id(string str)
{
  return str == name || str == alias || str == "air key";
}

int wear_fun(string str)
{
  write("You feel the urge to fly away...\n");
  say(TPN+" wears a silver necklace.  "+TP->QPRO+" looks very pretty.\n");
  return 1;
}

