#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) 
	return;
    set_light(1);
    short_desc="The Shadowhills";
    long_desc=
    ("You are in the Shadowhills, evil lurks everywhere.\n"+
      "to the east you see some mountains.\n");
    items=({
      "hills","Dark hills with no living things",
      "mountains","Some small mountains with an evil aura"
    });
    dest_dir=({
      "/players/sherman/hills/hill6","south",
      "/players/sherman/hills/hill7","west"
    });
}
