inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
void reset(int arg){

  ::reset(arg);
  if(arg) return;
      set_alias("puck");
      set_name("puck");
      set_race("fairy");
      set_short("Puck");
      set_long("This is an average sized fairy who is dressed in dark green.  There is a small gold coin "+
               "falling from his pocket.  He is said to be a master cobbler.\n");
      set_level(90 + random(5));
      set_al(50);
      set_gender(1);
}
