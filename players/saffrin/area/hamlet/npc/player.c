inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
object sword;

void reset(int arg){

  ::reset(arg);
  if (!arg) {
      set_name("player");
      set_race("human");
      set_short("A player");
      set_long("This is an actor from the theatre who is practicing his swordplay with anyone\n"+
                 "or anything he can find.\n");
      set_level(10);
      set_wc(0);
      set_ac(1);
      set_al(-1000);
      set_aggressive(1);
      set_gender(1);
      add_money(500 + random(500));

      MOVE(CLONE(HAM+"obj/plsword"),TO);
        init_command("wield sword");
  }
}
