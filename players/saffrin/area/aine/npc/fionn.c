inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
reset() {

  ::reset();
      set_alias("fionn");
      set_name("Fionn");
      set_race("man");
      set_short("Fionn");
      set_long("This warrior has graying hair from an enchanted lake and "+
	       "a brown goatee.  He was the potential lover of Aine until "+
               "Grian tricked him into graying his hair.\n");
      set_level(20 + random(10));
      set_al(-100);
      set_aggressive(1);
      set_gender(1);
      add_money(2500 + random(500));
      MOVE(CLONE(AINE+"obj/solar"),TO);
        init_command("wield sword");
}
