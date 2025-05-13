inherit "/room/room";

#include "/room/room_defs.h"

status _search(string str);

status i;

void reset(int arg) {
  i=0;
  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "Ruin";

  long_desc =
    "You are standing inside an old deserted ruin. " +
    "The roof has long since fallen down, and there " +
    "is no sign of a door. Heaps of rubble lie on " +
    "the ground, mainly coming from the walls, which " +
    "look as if they are now only half the height they "+
    "once were.\n";

  dest_dir = ({
    PLAIN + "plain08", "north",
    PLAIN + "plain09", "east",
    PLAIN + "plain03", "west",
    PLAIN + "plain04", "south",
  });

  items = ({
    "ruin", "This is an old deserted ruin",
    "roof", "The roof has not been here for a long time",
    "door", "You are not even sure where the door used to be",
    "rubble", "There is rubble everywhere. It might be " +
      "a good idea to search it",
    "heaps of rubble", "There is rubble everywhere. It " +
      "might be a good idea to search it",
    "heaps", "There is rubble everywhere. It might be a " +
      "good idea to search it",
    "walls", "The walls are crumbling badly. In a lot of " +
      "places, they are almost gone",
  });
}

void init() {
  ::init();
  add_action("_search","search");
}

status _search(string str) {
  object s;

  switch(str) {
    case "ruin" :
    case "roof" :
    case "door" :
    case "walls" :
      write("You search the " + str + " but find nothing.\n");
      say(lw(TP->NAME + " searches the " + str +
             " but finds nothing.\n"));
      return 1;
    case "rubble" :
    case "heaps" :
    case "heaps of rubble" :
      i = 1;
      write("You search the " + str + " and find a stethoscope!\n");
      say(lw(TP->NAME + " searches the " + str +
             " and finds something!\n"));
      s=clone_object("obj/stethoscope");
      if(transfer(s, TP)) {
        write("You are carrying too much.\n");
        move_object(s, TO);
      }
      return 1;
    default :
      notify_fail("Search what?\n");
      return 0;
  }
}

