inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
object sword, chainmail;

void reset(int arg){

  ::reset(arg);
  if (!arg) {
      set_alias("guard");
      set_name("denmark guard");
      set_race("human");
      set_short("A Denmark Guard");
      set_long("This is a guard who has sworn to protect the all of Denamrk.  He is standing at\n"+
                 "full attention, ready for anything.\n");
      set_level(25);
      set_wc(0);
      set_ac(2);
      set_al(-1000);
      set_aggressive(1);
      set_gender(1);
      add_money(2500 + random(500));

      MOVE(CLONE(HAM+"obj/dsword"),TO);
        init_command("wield sword");
      MOVE(CLONE(HAM+"obj/dmail"),TO);
        init_command("wear chainmail");
  }
}
