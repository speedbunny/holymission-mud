
inherit "obj/npc";
#include "../guild.h"

    reset(arg) {
     ::reset(arg);

     if (!arg) {
      set_name("praying monk");
      set_alt_name("monk");
      set_short("A praying monk");
      set_long("A monk who is kneeling down and praying.\n");
      set_gender(1);
      set_level(4);
      set_al(900);
      add_money(20);
      set_attacks(1);
      set_attacks_change(20);
      set_dodge(20);
      if (random(100)<12) {
      move_object(clone_object("players/whisky/guild/obj/mamulet2"),this_object());   }
      else {
      move_object(clone_object("players/whisky/guild/obj/mamulet"),this_object());   }
    }
  }
