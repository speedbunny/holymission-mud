inherit "room/room";

reset(tick){
    if(tick) return;
    short_desc=("A small lobby.\n");
    long_desc=("The lobby of the building is covered with trash. The walls\n"+
      "look like they are falling down, and the rug is smoking.\n"+
      "At the far end of the room is a large steel door. Judging\n"+
      "from the damage to the walls you think you could crash the\n"+
      "door down with no problem.\n");
    items=({"door", "It looks like you can bash it!\n"});
    clone_list=({1,4,"ss","players/akira/mobs/ss",0});
    ::reset(tick);
    property=({"vag_quest", "no_teleport"});
    dest_dir=({"players/akira/vag/city4", "south"});
}


init() {
	::init();
	add_action("_crash", "crash");
}


int _crash(string str){
    if(!str) {
	notify_fail("Crash what?");
	return 0;
    }
    if(str== "door"){
	this_player()->move_player("up#players/akira/vag/hroom");
	write("You break the door down and enter the next room!\n");
	return 1;
    }
}
