inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
reset(arg) {

  ::reset(arg);
  if (arg) return;
      set_alias("orc");
      set_name("Orc woman");
      set_race("woman");
      set_short("Orc woman");
      set_long("This orc woman is mate to an orc in the valley.  She is tall "+
               "and has slime oozing down from her chin.\n");
      set_level(5 + random(5));
      set_al(-100);
      set_aggressive(1);
      set_gender(2);
      add_money(500 + random(50));
}
