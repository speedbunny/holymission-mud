inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
object skull;

void reset(int arg){

  ::reset(arg);
  if (!arg) {
      set_name("yorick");
      set_race("yorick");
      set_short("Yorick");
      set_long("This the the skeleton of the former court jester whos died several decades\n"+
                 "ago.  He is carrying his skull in his hands.  Alas, Hamlet knew him well.\n");
      set_level(50);
      set_wc(0);
      set_ac(35);
      set_al(-1000);
      set_aggressive(1);
      set_gender(1);
      add_money(5000 + random(1000));

      MOVE(CLONE(HAM+"obj/skull"),TO);
        init_command("wield skull");
  }
}
