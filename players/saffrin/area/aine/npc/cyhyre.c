inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
reset() {
  ::reset();
      set_alias("cyhyraeth");
      set_name("cyhyraeth");
      set_race("fairy");
      set_short("cyhyraeth");
      set_long("This tiny little cyhyraeth is a type of fairy that cries and moans "+
	       "when someone is about to die.  She appears worried.\n");
      set_level(42+ random(10));
      set_al(200);
      set_gender(2);
      set_aggressive(1);
      add_money(2500 + random(400));
}
