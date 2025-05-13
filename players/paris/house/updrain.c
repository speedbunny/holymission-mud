inherit "room/room";
#include "/players/paris/house/house.h"

void reset(int arg) {
  if (arg)
    return;
  ::reset(arg);
  set_light(1);
  short_desc = "The top of the drainpipe";
  long_desc = "You find yourself at the top of the house, below you "
    + "you can see the garden and before you appears to be a window "
    + "to a bedroom. Perhaps you can look through it.\n";
  dest_dir = ({
    "players/paris/house/garden", "down",
  });
  items = ({
    "window", "A large glass window, perhaps you can look through it",
    "garden", "You can see the garden below you. Be careful you don't fall",
    "bedroom", "You can see the bedroom through the window",
  });
}

void init() {
  ::init();
  add_action("_goLook", "look");
  add_action("_goRead", "read");
}

int _goLook(string str) {
  if (str == "through window") {
    printf("You look through the window.\n"
	   + "Behind the window you can see a desk, it has some "
	   + "scraps of paper on it,\nperhaps you can read one "
	   + "of them?\n");
    say(this_player()->query_name()+" looks through the window.\n",
	this_player());
    return 1;
  } else 
    return 0;
}


