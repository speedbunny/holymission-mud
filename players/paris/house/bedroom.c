inherit "room/room";
#pragma strict_types
#include "/players/paris/house/house.h"

void reset(int arg) {
  if (arg)
    return;
  set_light(1);
  short_desc = "The magicians bedroom";
  long_desc = "You are standing in a plain chamber, a small bed lies "
    + "in the center of the room, floating in midair. Under the window "
    + "is a desk, on which some scraps of paper catches your eye.\n";
  dest_dir = ({
    "players/paris/house/upstairs1", "south",
  });
  items = ({
    "air", "Motes of dust dance in the light",
    "dust", "Ooooh, no one looks as if they have cleaned in here for years ",
    "window", "Hmm, you can 'look out of' it",
    "desk", "There is some scraps of paper here you should perhaps read ",
    "scraps of paper", "Perhaps you should read them ",
    "papers", "You might want to read the scraps of paper",
    
  });
  smell = "All the dust in the air makes you want to sneeze\nAcchoooo!\n";
  ::reset(arg);
}

void init() {
  ::init();
  add_action("_goLook", "look");
  add_action("_goRead", "read");
}

int _goLook(string str) {
  /* 
   * eventually will be able to look out the window and
   * see anyone standing in the garden
   */
  
  if (str != "out of window") 
    return 0;
  printf("You look out of the window\n");
  say(capitalize((string)this_player()->query_name())
      + " looks out of the window.\n", 
      this_player());
  return 1;
}
