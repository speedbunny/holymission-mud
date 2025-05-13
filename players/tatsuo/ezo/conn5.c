#define PPATH "/players/tatsuo/ezo/"

inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = "A narrow tunnel";
   long_desc = 
	"GASP! This tunnes is narrow. You hope that you won't get stuck\n"+
	"here! With the roughly hewn walls that have sharp stones tearing\n"+
	"at your clothing. You hope you don't have a claustriphobia\n"+
	"attack.  But looking north you can see light!  Better get out of\n"+
	"here quick. There is a large crack on the wall here as well.\n";
   dest_dir=({
	PPATH + "coast/rf6","north",
	PPATH + "conn4","south",
   });
}

init() {
   ::init( );
   add_action( "do_enter", "enter" );
}

do_enter(what) {
   if ( what != "crack" )
      return( 0 );
   this_player()->move_player( "into the wall#players/tatsuo/ezo/island_link/link1" );
   return( 1 );
}
