
inherit "obj/npc";
#include "../guild.h"

void reset(int arg) 
{
     ::reset(arg);
     if (arg) return;

      set_name("old monk");
      set_alt_name("monk");
      set_short("An old monk");
      set_long("A very weak and old monk.\n");
      set_gender(1);
      set_level(3);
      set_al(800);
      set_attacks(1);
      set_attacks_change(10);
      set_dodge(10);
      add_money(10);
      move_object(clone_object("players/whisky/guild/obj/mamulet"),this_object());
      }
void init()
{
  ::init();
    if (this_player()->query_race()=="goblin")
        attack_object(this_player());
}
