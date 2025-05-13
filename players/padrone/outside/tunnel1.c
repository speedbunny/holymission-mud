/* Tunnel 1 */
/* Checked - Exos 961028 */

inherit "players/cashimor/inherit/water";

reset(arg) {
    if(!arg) {
	short_desc="Underwater tunnel";
	long_desc="You are in a dark water-filled tunnel. You can leave the "
	+ "tunnel by going up, or you can follow the tunnel east. But it "
	+ "looks very narrow. There is also a tunnel to the west, but "
	+ "water is streaming to quickly out of it to enter it.\n";
	dest_dir=({"players/padrone/outside/tunnel2","east",
	  "players/cashimor/room/tunnel","west",
	  "players/padrone/outside/lake_bottom","up"});
	damage=2;
	items=({"water","The water feels deadly, but less deadly than elsewhere",
	  "tunnel","The water is streaming through it rather fast"});
    }
    ::reset(arg);
}

init() {
    ::init();
    add_action("west_it","west");
}

west_it() {
    write("You can't. The water is streaming too quickly.\n");
    say(this_player()->query_name()+" attempts to go west, but fails.\n");
    return 1;
}
