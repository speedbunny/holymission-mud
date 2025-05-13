
inherit "room/room";


reset(tick){
if(tick) return;
set_light(1);
short_desc=("Stone covered room.");
long_desc=(" ");
}

init(){
   ::init();

   add_action( "_reload", "reload" );

}

_reload(str){

object ob;

	if( str == "sling-staff" ) {

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

