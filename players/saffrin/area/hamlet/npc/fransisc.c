inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
object sword, chainmail;

void reset(int arg){

  ::reset(arg);
  if (!arg) {
      set_name("francisco");
      set_race("human");
      set_short("Francisco");
      set_long("A Denmark soldier who si trying very hard to become an officer.  His chainmail\n"+
                 "and sword are perfectly polished.\n");
      set_level(30);
      set_wc(1);
      set_ac(3);
      set_al(-1000);
      set_aggressive(1);
      set_gender(1);
      add_money(3000 + random(500));

      MOVE(CLONE(HAM+"obj/dsword"),TO);
        init_command("wield sword");
      MOVE(CLONE(HAM+"obj/dmail"),TO);
        init_command("wear chainmail");
  }
}
