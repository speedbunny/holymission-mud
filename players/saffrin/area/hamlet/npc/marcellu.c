inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
object sword, chainmail;

void reset(int arg){

  ::reset(arg);
  if (!arg) {
      set_name("marcellus");
      set_race("human");
      set_short("Marcellus");
      set_long("This is an officer of the Denmark army.  His eyes look open and alert.\n"+
                     "He has sworn to protect the country.\n");
      set_level(35);
      set_wc(3);
      set_ac(4);
      set_al(-1000);
      set_aggressive(1);
      set_gender(1);
      add_money(3500 + random(500));

      MOVE(CLONE(HAM+"obj/ofsword"),TO);
        init_command("wield sword");
      MOVE(CLONE(HAM+"obj/dmail"),TO);
        init_command("wear chainmail");
  }
}
