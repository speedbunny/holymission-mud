inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
void reset(int arg){

  ::reset(arg);
  if(arg) return;
      set_alias("brownie");
      set_name("brownie");
      set_race("fairy");
      set_short("A brownie");
      set_long("This is an average sized brownie at three feet tall.  He is dressed from head to "+
               "toe in all brown.  He has a small brown face and shaggy hair.\n");
      set_level(31 + random(5));
      set_al(-100);
      set_aggressive(0);
      set_gender(1);
      add_money(1000 + random(500));
}
