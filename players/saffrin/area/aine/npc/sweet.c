inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
reset() {

  ::reset();
      set_alias("meadowsweet");
      set_name("meadowsweet");
      set_race("flower");
      set_short("meadowsweet");
      set_long("This sweet smelling flower appears to dislike your presence "+
	       "and seeks to prevent you from finding its mistress, Aine.\n");
      set_level(20+ random(10));
      set_al(100);
      set_aggressive(1);
      set_gender(2);
      add_money(250 + random(50));
}
