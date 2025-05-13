inherit "room/room";

#include "/players/tamina/defs.h"

object folk;

void reset(int arg) 
{
  folk = present("folk");
  if (!folk)
  {
    folk = clone_object("obj/monster");

    folk->set_name("folk");
    folk->set_race("human");    
    folk->set_short("Scavenging Folk");
    folk->set_long(
  "These mad people run around the Petrified Forest, gathering up \n"+
  "all the little artifacts they can find.\n");
    folk->set_level(12);
    folk->set_wc(9);
    folk->set_ac(4);
    folk->set_spell_mess1("The Scavenging Folk go Wild !!\n");
    folk->set_spell_mess2("The Scavenging Folk go Bananas !!\n");
    folk->set_spell_dam(12);
    folk->set_chance(15);

    "/players/tamina/teds/random_treasure"->make_item(folk, 10);
    "/players/tamina/teds/random_treasure"->make_item(folk, 10);
    "/players/tamina/teds/random_treasure"->make_item(folk, 10);
    move_object(folk, this_object());
  }
  ::reset(arg);
  if(arg) return 0;

  set_light(1);
  short_desc = "Petrified Forest";
  long_desc =
"The forest is especially dense here, you have to push\n"+
"through undergrowth so thick you can see no more than\n"+
"an arms length in front of you.\n";

    dest_dir = ({
    TFOREST + "rm1", "north",
    TFOREST + "rmP", "south",
    TFOREST + "rmW", "east",
    });

}
