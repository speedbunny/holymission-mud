inherit "room/room";

void reset( int arg ) {
    if( !arg ) {
	set_light( 1 );
	short_desc = "Foyer of the Hall of the Harpers";
	long_desc = "\
You are in the foyer of the Hall of the Harpers.  The floor\n\
is the whitest marble, as are the walls.  The ceiling is\n\
vaulted and shows a mural of a young man battling a giant\n\
winged wolf.  A large staircase leads up, also of bright white\n\
marble.  Gilded doors lead out of the hall to the south.\n\
Large stained glass windows let in a plethora of multi-colored\n\
light.  Ornate archways lead to the exhibits in the hall.\n";
	items = ({ });
	dest_dir = ({
	  "/players/exos/areas/hall/hall2", "east",
	  "/players/exos/areas/hall/hall3", "north",
	  "/players/exos/areas/hall/hall4", "west",
	  "/players/exos/areas/hall/hall10", "up",
	});
    }
    replace_program( "room/room" );
    ::reset( arg );
}
