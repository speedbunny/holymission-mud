inherit "room/room";

#include "/players/redsexy/defs.h"

object chest, box;

int no_clean_up() {
  return 1;
}

reset(arg) {
  if(!chest) {
    chest = clone_object(GLD + "objects/storagechest");
    move_object(chest, TO);
  }
  if(!box) {
    box = clone_object(GLD + "objects/moneybox");
    move_object(box, TO);
  }
  if(arg) return;
  set_light(1);
  short_desc = "Storage Room";
  long_desc =
    "    This is a storage room, a place where more experienced\n" +
    "Summoners can leave items and money for their poor fellows.\n" +
    "Though the room is dim, you can make out many shelves and\n" +
    "racks lining the walls. If you have anything you can leave\n" +
    "here, please do.  You also notice a sign fixed on the wall.\n";

  dest_dir = ({
    GLD + "rooms/lounge", "west",
  });

  items = ({
    "room","A dimly-lit storage room",
    "shelves", "Dark shelves for storing items",
    "racks", "Racks for hanging weapons and armour",
    "walls", "The walls of the room are lined with racks and shelves",
  });
}

void init() {
   ::init();
   add_action("_read","read");

   }

int _read(string str) {

   if(str!="sign") return 0;
         write("You read the sign that is fixed up on the wall:\n");
         cat("/log/guild_donate");
//         this_player()->more("/log/guild_donate");
         return 1;
}

