inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
reset() {

  ::reset();
      set_alias("seelie");
      set_name("seelie");
      set_race("fairy");
      set_short("seelie");
      set_long("This tiny little seelie is a type of fairy that will avenge "+
	       "any injury.  She does not look pleased to see you.\n");
      set_level(36+ random(10));
      set_aggressive(1);
      set_al(200);
      set_gender(2);
      add_money(2500 + random(200));
}
