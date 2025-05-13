inherit "/room/room";

#include "/room/room_defs.h"

static int counter;

string garden_contents() {
  return "There be vegetables there";
}

void reset(int arg) {
  clone_list = ({
    1, 2, "bunny", "obj/monster", ({
      "set_name", "bunny",
      "set_race", "rabbit",
      "set_level", 2,
      "set_al", 25,
      "set_short" , "A cute bunny",
      "set_long", "A cute little bunny. It looks very harmless.\n",
      "set_size", 1,
    }),
  });

  counter = 10;

  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "In a beautiful garden";
  long_desc =
    "The northern center of the garden is reserved room for "+
    "Chantilly's bunnies to play. There is also a small "+
    "vegetable garden here.  @@garden_contents@@.  A wall "+
    "blocks travel to the north but the garden continues in "+
    "other directions.\n";

  items = ({ 
    "wall","The wall to the north blocks that direction",
    "garden", garden_contents(),
  });

  dest_dir = ({
    VILLAGE_GARDEN + "garden6", "east",
    VILLAGE_GARDEN + "garden4", "west",
    VILLAGE_GARDEN + "garden2", "south",
  });
}

void init() {
  ::init();
  add_action("_pick", "pick");
}

status _pick(string str) {
  object ob;

  switch(str) {
    case "vegetable" :
    case "vegetables" :
    case "a vegetable" :
      if(counter <= 0 ) {
        write("The garden is empty.\n");
        return 1;
      }
      write("You pick a vegetable.\n");
      return 1;
      
    default :
      notify_fail("Pick what?\n");
      return 0;
  }
}

