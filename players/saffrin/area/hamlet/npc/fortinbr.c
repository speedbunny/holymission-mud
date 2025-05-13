inherit "/obj/monster";
#include "/players/saffrin/defs.h"
     
object cape, sword, shield;

void reset(int arg){

  ::reset(arg);
  if (!arg) {
      set_name("fortinbras");
      set_race("human");
      set_short("Fortinbras");
set_long("This the handsome young  Prince of Norway who is visiting Denmark on buisness\n"+
                 "for his country.\n");
      set_level(100);
      set_wc(0);
      set_ac(9);
      set_al(-1000);
      set_aggressive(1);
      set_gender(1);
      add_money(10000 + random(1000));

      MOVE(CLONE(HAM+"obj/fsword"),TO);
        init_command("wield sword");
      MOVE(CLONE(HAM+"obj/fshield"),TO);
        init_command("wear shield");
      MOVE(CLONE(HAM+"obj/fcape"),TO);
        init_command("wear cape");
  }
}
