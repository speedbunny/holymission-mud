inherit "room/room";
#pragma strict_types

void reset(int arg) {
  if (arg)
    return;
  set_light(0);
  short_desc = "A dark tunnel";
  long_desc = "You are in a long, dark tunnel. On the south wall is a small"
    + " lever and a fireplace, the passage continues to the north. You "
    + "really don't think you should continue.\n";
  dest_dir = ({
    "players/paris/house/tunnel2", "north",
  });
  items = ({
    "air", "Motes of dust dance in the light",
    "fireplace", "A simple stone fireplace",
    "dust", "Ooooh, no one looks as if they have cleaned in here for years ",
    "lever", "You think you can pull it",
  });
  smell = "All the dust in the air makes you want to sneeze\nAcchoooo!\n";
  ::reset(arg);
}

void init() {
  ::init();
  add_action("_goPull", "pull");
}

int _goPull(string str) {
  if (str == "the lever" || str == "lever") {
    printf("You pull the lever, causing the fireplace to rotate, and you "
	   + "quickly move through.\n");
    tell_room("players/paris/house/study",
	      "The fireplace starts to rotate and "
	      + capitalize((string)this_player()->query_name()) 
	      + " quickly nips out as it closes.\n");
    this_player()->move_player("through the fireplace#players/paris/house/study");
    return 1;
  }
  return 0;
}
