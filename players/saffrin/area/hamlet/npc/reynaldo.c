inherit "/obj/monster";
#include "/players/saffrin/defs.h"
 
object duster;

void reset(int arg){

  ::reset(arg);
  if (!arg) {
      set_name("reynaldo");
      set_race("human");
      set_short("Reynaldo");
      set_long("This is Polonius's not too brave servent.  He is cowering in the corner, craddling\n"+
                 "his head in his hands.\n");
      set_level(25);
      set_wc(0);
      set_ac(7);
      set_al(1000);
      set_gender(1);
      add_money(2500 + random(500));

     MOVE(CLONE(HAM+"obj/duster"),TO);
        init_command("wield duster");
  }
}
