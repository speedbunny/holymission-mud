inherit "/obj/monster";
#include "/players/saffrin/defs.h"

object sword, crown, robe;

void reset(int arg){

  ::reset(arg);
  if (!arg) {
     set_name("king Claudius");
     set_alias("king");
     set_race("human");
     set_short("King Claudius");
     set_long("A greedy man who is said to have murdered his brother to obtain the\n"+
                "throne of Denmark.\n");
     set_level(100);  
     set_wc(0);
     set_ac(11);
     set_al(-1000);
     set_aggressive(1);
     set_gender(1);
     add_money(10000 + random(1000));

     MOVE(CLONE(HAM+"obj/clasword"),TO);
        init_command("wield sword");
     MOVE(CLONE(HAM+"obj/clacrown"),TO);
        init_command("wear crown");
     MOVE(CLONE(HAM+"obj/clarobe"),TO);
        init_command("wear robe");
  }
}
