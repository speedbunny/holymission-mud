inherit "room/room";

void reset( int arg ) {
    if( !arg ) {
	set_light( 1 );
	short_desc = "The Forbidden Crypt";
	long_desc = "\
You are in the Forbidden Crypt of Exos.  This is where he rests during the\n\
day, as dreams of world domination and fresh white necks drift through his\n\
evil mind.  The walls are cloaked in black velvet curtains.  Blood-Red\n\
candles glow constantly, creating eery effects on the black curtains.  A very\n\
ornate coffin lays upon a gilded dais, surrounded by 5 large black\n\
candelabras.  A bloody pentagram is engraved in the floor with the dais at its\n\
exact center.  There are white portals around the room so the Evil One may\n\
have direct access to his domains.\n";
	dest_dir = ({ 
	  "/room/church", "church",
	  "/players/matt/newworld/city/rooms/votebooth", "vote",
	  "/room/post", "post",
	  "/players/exos/guild/rooms/bard1", "b1",
	  "/players/exos/forest/edge1", "forest",
	  "/players/exos/elfcity/wall1", "regulost",
	  "/players/exos/areas/hall/hall1", "hall",
	});
	property = ({ "no_fight", "no_sneak", "no_steal", "has_fire" });
	smell = "Odd this area does not smell at all!\n";
    }
    replace_program( "room/room" );
    ::reset( arg );
}                    
