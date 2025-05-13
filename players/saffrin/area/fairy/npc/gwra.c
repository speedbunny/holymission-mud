inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
void reset(int arg){

  ::reset(arg);
  if(arg) return;
      set_alias("annwn");
      set_alt_name("gwragedd");
      set_name("gwragedd annwn");
      set_race("fairy");
      set_short("A gwragedd annwn");
      set_long("This is a tiny lake fairy who is dressed from head to toe in white and silver.  "+
               "She has soft glowing wings that grace her back.\n");
      set_level(29 + random(5));
      set_al(50);
      set_aggressive(0);
      set_gender(2);
      add_money(800 + random(500));
}
