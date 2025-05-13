inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
void reset(int arg){

  ::reset(arg);
  if (arg) return;
      set_alias("fendoeree");
      set_name("fendoeree");
      set_race("fairy");
      set_short("A fendoeree");
      set_long("This is a large variety of brownie who is very ugly and hairy.  He is dressed from head to "+
               "toe in all brown.  He has a small brown face and shaggy hair.\n");
      set_level(33 + random(5));
      set_al(50);
      set_aggressive(0);
      set_gender(1);
      add_money(1100 + random(500));
}
