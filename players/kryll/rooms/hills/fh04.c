inherit "room/room";

#include "/players/kryll/rooms/room_defs.h"
#include "/players/kryll/include/rnd_stone.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  short_desc = "A jeweled fork";
  long_desc =
    "The path splits east and west around a huge outcropping of "+
    "rock. The rock sparkles with lots of beautiful stones with "+
    "many different colors.\n";

  set_light(1);

  items = ({
    "mountain","The mountain to the north is the tallest mountain " +
      "around and the peak is obscured by the clouds",
    "clouds","Large fluffy things floating in the sky",
    "outcropping","Possibly a vein of gems",
    "rock","It sparkles because of the gems",
    "vein","It is unusual since most veins have only one type of "+
      "gem in it",
    "gems","Lots of different kinds. But they usually aren't found "+
      "together. With the right equipment, maybe they could be dug up",
    "stones","Lots of different kinds. But they usually aren't "+
      "found together. With the right equipment, maybe you can dig "+
      "them up",
    "foothills","Rough, rocky hills",
    "rocks","They block all the other exits",
    "path","It is natural and not cut",
  });

  smell = "\nEvil can definitely be smelled nearby.\n\n";

  dest_dir = ({
    HILLS + "fh10", "east",
    HILLS + "fh05", "west",
    HILLS + "fh03", "south",
  });
}

void init() {
  ::init();
  add_action("_mine", "dig");
  add_action("_mine", "mine");
}

status _mine(string str) {
  object stone;

  switch(str) {
    case "gem":
    case "up gem":
    case "gems":
    case "up gems":
    case "stone":
    case "up stone":
    case "stones":
    case "up stones":
    case "vein":
    case "in vein":
    case "rock":
    case "in rock":
    case "outcropping":
    case "in outcropping": {
      if(present("pickaxe", TP) || present("shovel", TP)) {
        stone = clone_object(rndStone());
        writelw("You chip at the rock, until you free one " +
                stone->NAME + ".\n");
        if(transfer(stone, TP) != 0) {
          writelw("You are too encumbered to carry the gem, and it "+
                  "falls to the ground.\n");
          say(lw(CAP(TP->NAME) + " chips at the rock, letting a "+
              stone->NAME + " fall to the ground.\n"));
          MOVE(stone, TO);
        }
        else {
          writelw("You grab the gem quickly.\n");
          say(lw(CAP(TP->NAME) + " chips at the rock and grabs a gem.\n"));
        }
        return 1;
      }
      else 
        writelw("You do not have the right equipment to mine "+
                "for gemstones. You need a shovel or a pickaxe.\n");
      return 1;
    }
    default: {
      notify_fail("Mine what?\n");
      return 0;
    }
  }
}
