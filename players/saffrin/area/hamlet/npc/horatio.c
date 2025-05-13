inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
object sword, chainmail;

void reset(int arg){

  ::reset(arg);
  if (!arg) {
      set_name("horatio");
      set_race("human");
      set_short("Horatio");
      set_long("This the very loyal best friend of Hamlet.  He is standing with perfect posture\n"+
                 "and looks alert.\n");
      set_level(75);
      set_wc(0);
      set_ac(10);
      set_al(-1000);
      set_aggressive(1);
      set_gender(1);
      add_money(7500 + random(1000));

      MOVE(CLONE(HAM+"obj/thrsword"),TO);
        init_command("wield sword");
      MOVE(CLONE(HAM+"obj/thrmail"),TO);
        init_command("wear chainmail");
  }
}
