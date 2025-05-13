/* 031393 Changed by Llort to room/room */

inherit "room/room";

reset(arg) {
    if(!arg) {
        set_light(1);
	short_desc="Storage room";
        long_desc=
	 "This is a special storage room inside Padrone's tower.\n" +
	 "Normally, it should be impossible to get here.\n";
        dest_dir=({
            "players/padrone/workroom", "down",
                 });
    }
}

move() {
    if (!this_player()->query_immortal()) { 
	write("That door can only be used by the one who built it.\n"); 
	write("You seem to be stuck here. Sorry.\n"); 
	return 1; 
    }
    return ::move();
}
