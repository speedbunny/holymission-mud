#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) 
	return;
    set_light(1);
    short_desc="The Shadowhills";
    long_desc=
    ("You are in the Shadowhills, evil lurks everywhere.\n");
    items=({
      "hills","Dark hills with no living things on them"
    });
    dest_dir=({
      "/players/sherman/hills/hill4","north",
      "/players/sherman/hills/hill2","east",
      "/players/sherman/darkl9","south"
    });
}
