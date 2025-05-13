
inherit "room/room";

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="Village shore";
        long_desc="The village shore. A jetty leads out to the east.\n";
        dest_dir=({
            "room/vill_shore3","west",
/*
            "players/qwerty/room/newent","north",
*/
	    "players/uglymouth/vikings/shore1","south",
            "room/jetty2","east",
                 });

/* Airborne - 05/12/93 */
replace_program("room/room");

    }
}
