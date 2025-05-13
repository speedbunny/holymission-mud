inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
object sword, chainmail;

void reset(int arg){

  ::reset(arg);
  if (!arg) {
      set_name("rosencrantz");
      set_race("human");
      set_short("Rosencrantz");
      set_long("A stately young courtier that is standing with perfect posture.  He looks a bit\n"+
                     "bored as he yawns.\n");
      set_level(50);
      set_wc(0);
      set_ac(7);
      set_al(-1000);
      set_aggressive(1);
      set_gender(1);
      add_money(5000 + random(1000));

      MOVE(CLONE(HAM+"obj/csword"),TO);
        init_command("wield sword");
     MOVE(CLONE(HAM+"obj/cmail"),TO);
        init_command("wear chainmail");
  }
}
