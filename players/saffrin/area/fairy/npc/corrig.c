inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
void reset(int arg){

  ::reset(arg);
  if(arg) return;
      set_alias("corrigan");
      set_name("corrigan");
      set_race("fairy");
      set_short("A corrigan");
      set_long("This beautiful, blonde haired fairy is said to have a dark side.  "+
               "She turns into a hag at night.\n");
      set_level(53 + random(5));
      set_al(50);
      set_aggressive(0);
      set_gender(2);
      add_money(1100 + random(500));
}
