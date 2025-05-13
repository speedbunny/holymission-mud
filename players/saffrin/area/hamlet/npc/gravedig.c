inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
object shovel;

void reset(int arg){

  ::reset(arg);
  if (!arg) {
      set_name("gravedigger");
      set_alias("digger");
      set_race("human");
      set_short("A gravedigger");
      set_long("An old man with dirt all over his clothes and hands.  His face appears to\n"+
                 "be weather beaten.\n");
      set_level(25);
      set_wc(0);
      set_ac(7);
      set_al(-1000);
      set_aggressive(1);
      set_gender(1);
      add_money(2500 + random(500));

      MOVE(CLONE(HAM+"obj/shovel"),TO);
        init_command("wield shovel");
  }
}
