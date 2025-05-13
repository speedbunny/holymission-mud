#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) 
	return;
    set_light(1);
    short_desc="The Shadowhills";
    long_desc=
    ("You are now in a vally surrounded by the Shadowhills.\n");
    items=({
      "vally","A dark cold unfriendly vally",
      "hills","Dark hills with no living things"
    });
    dest_dir=({
      "/players/sherman/hills/hill7","north",
      "/players/sherman/hills/hill6","east",
      "/players/sherman/hills/hill2","south",
      "/players/sherman/hills/hill4","west"
    });
}
