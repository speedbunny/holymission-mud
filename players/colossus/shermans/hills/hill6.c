#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) 
	return;
    set_light(1);
    short_desc="In front of a cave";
    long_desc=
    ("You are in the Shadowlands. In front of you is a cave.\n");
    items=({
      "hills","Dark hills with no living things",
      "skeletons","Some victims of the cave-monster",
      "skeleton","A victim of the cave-monster",
      "cave","A very big cave. Many skeletons are here, some are crumbled to\n"+
      "dust"
    });
    dest_dir=({
      "/players/sherman/hills/hill8","north",
      "/players/sherman/hills/hill3","south",
      "/players/sherman/hills/hill5","west"
    });
}

void init(){
    ::init();
    add_action("enter","enter");
}

status enter(string str){
    if(str!="cave"){
	notify_fail("Enter what?\n");
	return 0;
    }
    this_player()->move_player("enter#players/sherman/hills/cave1");
    return 1;
}
