inherit "room/room";
 
reset(arg) {
    if (arg) return;
 
    ::reset(arg);
/*  set_outdoors(0);   */
    set_light(1);
    short_desc = "Cave of light";
    no_castle_flag = 0;
    long_desc = 
        "Magical cave\n\n"
        + "     You seem to be in a magical cave. The cave walls all\n"
        + "     emit a bright white light. The light is so bright that\n"
        + "     no light source is needed here.\n"
        + "     There is stairway leading up here.\n\n";
    dest_dir = 
        ({
        "players/animal/cave/12", "north",
        "players/animal/cave/2", "east",     
	"players/animal/light/light6","up",
        });
}
 
query_long() {
    return long_desc;
}
query_outdoorness() {
    return 0;
}
query_light() {
    return 1;
}
init() {
		::init();
		add_action("north","north");
}

north() {
	int r;
		r = random(10);
if(r <= 3) {
		call_other(this_player(),"move_player",
		"east#players/animal/cave/7");
			return 1;
	}
}
