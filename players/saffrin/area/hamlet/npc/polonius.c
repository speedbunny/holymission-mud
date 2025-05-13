inherit "/obj/monster";
#include "/players/saffrin/defs.h"
    
object sword, chainmail;

void reset(int arg){

  ::reset(arg);
  if (!arg) {
      set_name("polonius");
      set_race("human");
      set_short("polonius");
      set_long("This is an older man who is father to Opehlia and Laertes.  His brow is\n"+
                 "up into a worried frown.\n");
      set_level(75);
      set_wc(0);
      set_ac(35);
      set_al(1000);
      set_aggressive(1);
      set_gender(1);
      add_money(7500 + random(1000));

      MOVE(CLONE(HAM+"obj/thrsword"),TO);
        init_command("wield sword");
      MOVE(CLONE(HAM+"obj/thrmail"),TO);
        init_command("wear chainmail");
  }
}
