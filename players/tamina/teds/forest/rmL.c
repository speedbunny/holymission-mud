inherit "room/room";

#include "/players/tamina/defs.h"

object minotaur, steak;

void reset(int arg) 
{
  minotaur = present("minotaur");
  if (!minotaur)
  {
    minotaur = clone_object("obj/monster");

    minotaur->set_name("minotaur");
    minotaur->set_race("human");
    minotaur->set_gender(1);
    minotaur->set_long(
  "This is a huge manlike creature with the head of a bull.\n");
    minotaur->set_aggressive(1);
    minotaur->set_level(20);
    minotaur->set_wc(23);
    minotaur->set_ac(8);
    minotaur->set_al(-250);

    steak = CLO (TEDS + "foodstuffs/steak");
    MO(steak, minotaur);
    call_other("players/tamina/teds/random_armor","make_item",minotaur,20);
    call_other("players/tamina/teds/random_weapon","make_item",minotaur,20);
    MO(minotaur, TO);
  }
  if (arg) return 0;

  set_light(0);
  short_desc = "Dark Caves";
  long_desc =
"There is a straw pallet and a table in this cave.\n"+
"The overwhelming smell of cattle permeates the air,\n"+
"making it hard to breathe.\n";

    dest_dir = ({
    TFOREST + "rmR", "north",
    TFOREST + "rmK", "west",
    });

}
