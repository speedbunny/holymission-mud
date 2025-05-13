/* 031393 Changed by Llort to room/room */
/* 040794: Nokey: strict typed this */
#pragma strict_types
#pragma save_types

inherit "room/room";

void reset(int arg) {
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

varargs int move(string str) {
    if (!this_player()->query_immortal()) { 
	write("That door can only be used by the one who built it.\n"); 
	write("You seem to be stuck here. Sorry.\n"); 
	return 1; 
    }
    return ::move(str);
}
