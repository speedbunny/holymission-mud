
inherit "/obj/npc";
#include "../guild.h"

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_name("nun");
      set_alt_name("young nun");
      set_short("A young nun");
      set_long("A young beautiful nun.\n");
      set_gender(2);
      set_level(14);
      set_whimpy(4);
      set_al(400);
      add_money(100+random(50));
      set_attacks(2);
      set_attacks_change(30);
      set_dodge(20);
      move_object(clone_object(OBJ+"mace"),this_object());
      command("wield mace");
      }
init()
{
  ::init();
}
