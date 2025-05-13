inherit "/room/room";
 
#include "/room/room_defs.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "In a beautiful garden";
  no_castle_flag = 0;

  long_desc =
    "This is the entrance to Chantilly's beautiful garden. To the "+
    "north is Chantilly's house, while to the east is the garden. "+
    "The garden is the place where the young go and play and "+
    "see nature at its best. The town wall is directly south "+
    "and protects the villages from evil which lurks in the wilderness.\n";

  items = ({
    "garden", "Chantilly is well-known for her beautiful garden",
    "wall", "The town wall prevents going south and is too "+
      "difficult to climb",
    "house", "Chantilly's house is a beautiful two-story stone house. "+
      "You would have to look at the door to see if it were locked, "+
      "otherwise, you could just enter it",
    "door", "@@door_lock@@",
  });

  dest_dir = ({
    VILLAGE_GARDEN + "garden1", "east",
    HM_VILLAGE + "street18", "west",
  });
}

void init() {
  ::init();
  add_action("_enter", "enter");
}

string door_look() {
  return "Blah";
}

status _enter(string str) {
  switch(str) {
    case "house" :
    case "north" :
    case "Chantilly's house" :
    case "the house" :
      write("You cannot enter Chantilly's house yet!\n");
      return 1;
    default :
      notify_fail("Enter what?\n");
      return 0;
  }
}

