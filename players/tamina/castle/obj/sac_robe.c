#include "/players/tamina/defs.h"

inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;

   set_name("red robe");
   set_alias("robe");
   set_type("armour");
   set_short("Red Robe");
   set_long(
 "A very large robe of a deep, blood-red cloth, that feels very warm when\n"+ 
 "it closes around your body...\n");
   set_value(1500);
   set_ac(2);
   set_weight(4);
}

int wear(string arg) 
{
  if(!arg || !id(arg)) return 0;

  if (TP->query_alignment() > -50) 
  {
    write("When you put on the robe, you feel decidedly uneasy,\n"+
          "and want to take it off...\n");
    return 1;
  }

  if (::wear(arg)) 
  {
    write("You sense that this robe is true to your own outlook.\n");
  }
  return 1;
}

query_mage_wear()  { return 1; }
query_monk_wear()  { return 1; }
query_ninja_wear() { return 1; }


