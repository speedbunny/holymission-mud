
inherit "room/room";


reset(tick){
    if(tick) return;
    set_light(1);
    short_desc=("Stone covered room.");
    long_desc=("This is a small room with many stones covering the floor.\n"+
      "The stones very in size and shape, but most are small.\n");
    items=({"stones", "They look loke they could fit a sling." });

    dest_dir = ({
      "/players/nylakoorub/4th/quest/revisit_room",
      "south",
    });

    property = ({ "vag_quest", "no_teleport" });

}

init(){
    ::init();

    add_action( "_reload", "reload" );

}

_reload(str){

    object ob;

    if( str == "weapon" ) {

	ob = present( "staff-sling", this_player() );

	if( ob ) {
	    destruct( ob );
	    return 0;
	}

	move_object( clone_object( "players/akira/vag/staff" ),
	  this_player() );
	write( "You grab some stones and reload your Sling-Staff.\n" );

	return 1;

    }

    else write( "What would you like to reload? \n" );
    return 1;

}

