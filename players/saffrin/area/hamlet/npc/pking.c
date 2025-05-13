inherit "/obj/monster";
#include "/players/saffrin/defs.h"

object sword, crown;

void reset(int arg){

  ::reset(arg);
  if (!arg) {
      set_name("player king");
      set_alias("king");
      set_race("human");
      set_short("The Player King");
      set_long("This is the mighty player king who is leader of all the players.  He likes to\n"+
                     "ape what others do.\n");
      set_level(12);
      set_wc(0);
      set_ac(1);
      set_al(-1000);
      set_aggressive(1);
      set_gender(1);
      add_money(1000 + random(1000));

      MOVE(CLONE(HAM+"obj/pksword"),TO);
        init_command("wield sword");
      MOVE(CLONE(HAM+"obj/pkcrown"),TO);
        init_command("wear crown");
  }
}
