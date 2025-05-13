inherit "room/room";

#include "/players/tamina/defs.h"

object minotaur, steak;

void reset(int arg) 
{
  if (arg) return 0;
  set_light(0);
  short_desc = "Dark Cave";
  long_desc =
"There is a straw pallet and a table in this cave.\n"+
"The overwhelming smell of cattle permeates the air,\n"+
"making it hard to breathe.\n";

    dest_dir = ({
    TFOREST + "forest13", "south"
    });

  if (!present("minotaur")) 
  {
    minotaur = clone_object("obj/monster");

    minotaur->set_name("minotaur");
    minotaur->set_race("human");
    minotaur->set_gender(1);
    minotaur->set_long(
  "This is a huge manlike creature with the head of a bull.\n");
    minotaur->set_aggressive(1);
    minotaur->set_level(17);
    minotaur->set_wc(22);
    minotaur->set_ac(8);
    minotaur->set_al(-250);

    steak = CLO (TEDS + "foodstuffs/steak");
    MO(steak, minotaur);
    call_other("players/tamina/teds/random_armor","make_item",minotaur,17);
    call_other("players/tamina/teds/random_weapon","make_item",minotaur,17);
    MO(minotaur, TO);
  }
}
