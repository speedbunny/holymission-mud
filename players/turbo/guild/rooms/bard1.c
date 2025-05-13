inherit "room/room";

void reset( int arg ) {
    if( !arg ) {
	set_light( 1 );
	short_desc = "Harper Safe House";
	long_desc =
	"You have entered one of many Harper Safe Houses that are \
scattered around the landscape of Holy Mission.  This particular \
safe house includes a board for wandering bards to leave \
messages for their brethren, and also a donation cup, so that \
richer bards may help out bards that are down on their luck.\n";
	smell = "This room smells a tad earthy.";
	dest_dir = ({
	  "room/plane5", "out",
	});
	items = ({
	  "room", "A Harper Safe House",
	});
	clone_list = ({
          1, 1, "board", "/boards/guilds/bard_guild", 0,
	  1, 1, "cup", "players/turbo/guild/obj/donation_cup", 0,
	});
	property = ({
	  "no_fight","no_steal","no_sneak",
	});
    }
    ::reset( arg );
    replace_program( "room/room" );
}
