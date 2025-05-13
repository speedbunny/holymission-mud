inherit "/obj/monster";
#include "/players/saffrin/defs.h"
     
void reset(int arg){

  ::reset(arg);
  if (!arg) {
      set_alias("ghost");
      set_name("a graveyard ghost");
      set_race("undead");
      set_short("A graveyard ghost");
      set_long("This is a ghost that haunts the gloomy graveyard.  It appears to you as a gray\n"+
                 "cloud, nothing more.\n");
      set_level(15);
      set_wc(6);
      set_ac(6);
      set_al(-1000);
      set_aggressive(1);
      set_gender(1);
      add_money(1500 + random(500));
  }
}
