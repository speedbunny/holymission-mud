inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
reset() {

  ::reset();
      set_alias("olum");
      set_name("Ailill Olum");
      set_race("ailill");
      set_short("Ailill Olum");
      set_long("This king of Munster is passionately lusting after Aine.  "+
               "He is a coward who seeks to take all that he can get "+
               "through unjust means.\n");
      set_level(1+ random(10));
      set_al(-100);
      set_whimpy(1);
      set_gender(1);
      add_money(25 + random(5));
      MOVE(CLONE(AINE+"obj/chick"),TO);
        init_command("wield sword");
      MOVE(CLONE(AINE+"obj/cshield"),TO);
        init_command("wear shield");
}
