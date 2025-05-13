inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
void reset(int arg){

  ::reset(arg);
  if(arg) return;
      set_alias("pisky");
      set_name("pisky");
      set_race("fairy");
      set_short("A pisky");
      set_long("This is a tiny fairy who is dressed from head to toe in green and brown.  "+
               "She has soft glowing wings that grace her back.\n");
      set_level(25 + random(5));
      set_al(50);
      set_aggressive(0);
      set_gender(2);
      add_money(500 + random(500));
}
