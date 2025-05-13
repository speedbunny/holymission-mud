inherit "/obj/armour";

#include "/players/tamina/defs.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("diamond ring");
  set_alias("diamond");
  set_type("ring");
  set_ac(0);
  set_weight(1);
  set_value(150 + random(851));
  set_light(3);
  set_short("A Diamond Ring");
  set_long("A huge sparkling diamond ring, that still feels strangely heavy "+ 
           "to the touch. \nThere is a little message engraved inside the "+
           "band...\n");
  set_read("...From whence we came, and to thither we all must go...\n");
}

int query_monk_wear()  { return 1; }
int query_ninja_wear() { return 1; }
int query_mage_wear()  { return 1; }

int id(string str)
{
  return str == name || str == "diamond" || str == type[0] ||
	    str == "earth key";
}

int wear_fun(string str)
{
  write("When you put the Diamond Ring on your finger,\n"+
        "you feel a distinct urge to go underground...\n");
    say(TPN+" wear's the Diamond Ring.\n");

  return 1;
}
