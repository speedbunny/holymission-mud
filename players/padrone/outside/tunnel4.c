/* Tunnel4 */
/* File checked - Exos 961028 */

inherit "players/cashimor/inherit/water";

reset(arg) {
    if(!arg) {
	short_desc="Water-filled tunnel";
	long_desc="You are in a dark water-filled tunnel.\n";
	dest_dir=({"players/padrone/outside/tunnel3","west",
	  "room/sea_bottom","east"});
	damage=2;
    }
    ::reset(arg);
}

init() {
    ::init();
    add_action("west_it","west");
    add_action("east_it","east");
}

west_it() {
    write("The tunnel is too narrow to turn in!\n");
    say(this_player()->query_name()+" wanted to go back, but failed.\n");
    return 1;
}

east_it() {
    write("The tunnel is becoming narrower, and the water faster.\n"
      + "You're carried away and can't control where you're going.\n");
    say(this_player()->query_name()+" is carried away with the flow.\n");
}
