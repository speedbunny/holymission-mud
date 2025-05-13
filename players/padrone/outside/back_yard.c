inherit "room/room";

void reset( int arg ) {
    if( !arg ) {
	set_light( 1 );
	short_desc = "Back yard";
	long_desc=
	"You are standing in the back yard, behind Padrone's Castle.\n"+
	"There is a door leading north into the house, probably to the kitchen\n" +
	"(sniff sniff), and another door seems to be leading down into the cellar.\n" +
	"You can follow the small path around the castle, either to the west\n" +
	"or to the east, and another small path leads south, into the bushes.\n";
	dest_dir=({
	  "/players/padrone/inside/kitchen", "north",
	  "/players/padrone/inside/coal_cellar", "down",
	  "/players/padrone/outside/sw", "west",
	  "/players/padrone/outside/se", "east",
	  "/players/padrone/vdb1", "south",
	});
    }
    ::reset( arg );
    replace_program( "room/room" );
}
