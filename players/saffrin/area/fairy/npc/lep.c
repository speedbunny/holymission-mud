inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
void reset(int arg){

  ::reset(arg);
  if(arg) return;
      set_alias("lepracaun");
      set_name("lepracaun");
      set_race("fairy");
      set_short("A lepracaun");
      set_long("This is an average sized fairy who is dressed in dark green.  There is a small gold coin "+
               "falling from his pocket.  He is said to be a master cobbler.\n");
      set_level(27 + random(5));
      set_al(50);
      set_aggressive(1);
      set_gender(1);
      add_money(750 + random(500));
}
