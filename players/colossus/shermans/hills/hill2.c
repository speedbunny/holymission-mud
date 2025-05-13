#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) 
	return;
    set_light(1);
    short_desc="The Shadowhills";
    long_desc=
    ("You are in the Shadowhills, evil lurks everywhere.\n"+
      "to the south you see a small house.\n");
    items=({
      "hills","Dark hills with no living things",
      "house","It looks like a bar"
    });
    dest_dir=({
      "/players/sherman/hills/hill5","north",
      "/players/sherman/hills/hill3","east",
      "/players/sherman/vampirebar","south",
      "/players/sherman/hills/hill1","west"
    });
}
