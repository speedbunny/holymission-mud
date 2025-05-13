inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
reset() {

  ::reset();
      set_alias("spirit");
      set_name("dryad");
      set_race("spirit");
      set_short("dryad");
      set_long("This tree spirit hovers around the branches and leaves "+
	       "around you.  It appears to be slightly transparent.\n");
      set_level(9+ random(10));
      set_al(-100);
      set_aggressive(1);
      set_gender(2);
      add_money(25 + random(10));
}
