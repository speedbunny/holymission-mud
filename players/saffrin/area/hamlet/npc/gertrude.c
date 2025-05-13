inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
object goblet, robe, crown;

void reset(int arg){

  ::reset(arg);
  if (!arg) {
      set_name("Queen Gertrude");
      set_alias("queen");
      set_race("human");
      set_short("Queen Gertrude");
      set_long("An older woman who is not as sweet as she looks.  She married her dead\n"+
                 "husband's brother.  She is Hamlet's mother.\n");
      set_level(75);
      set_wc(0);
      set_ac(9);
      set_al(-1000);
      set_aggressive(1);
      set_gender(2);
      add_money(7500 + random(1000));

      MOVE(CLONE(HAM+"obj/goblet"),TO);
        init_command("wield goblet");
      MOVE(CLONE(HAM+"obj/gerrobe"),TO);
        init_command("wear robe");
      MOVE(CLONE(HAM+"obj/gercrown"),TO);
        init_command("wear crown");
  }
}
