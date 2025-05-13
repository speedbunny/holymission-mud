#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) 
	return;
    set_light(0);
    short_desc="Inside a big cave";
    long_desc=
    ("You are standing in a big dark dry cave.\n");
    items=({
      "cave","A big dry and dark cave"
    });
    dest_dir=({
      "/players/sherman/hills/cave8","east",
      "/players/sherman/hills/cave6","up"
    });
}
