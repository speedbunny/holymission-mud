
inherit "obj/npc";
#include "../guild.h"

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_name("singing monk");
      set_alt_name("monk");
      set_short("A singing monk");
      set_long("A monk, who is singing in a humming voice.\n");
      set_gender(1);
      set_level(8);
      set_whimpy(8);
      set_al(300);
      set_attacks(1);
      set_attacks_change(30);
      set_dodge(20);
      add_money(30);
     move_object(clone_object("/players/whisky/guild/obj/sandales"),this_object());
      }
