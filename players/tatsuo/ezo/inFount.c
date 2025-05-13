#define PPATH "/players/tatsuo/ezo/"
#define TP  this_player()

inherit "room/room";
object ninja;
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "Diving in a strange liquid";
   long_desc = 
     "You are diving in the strange liquid you have seen from above.\n" +
     "Soon, the fluorescent liquid is filling your eyes and your sight\n"+
     "becomes worse and worse... Already you are having trouble seeing\n" +
     "the walls of the tube !!!!\n" +
     "Are you doomed to drown ??!!\n";
   items=({
	"wall","You see the faint outlines of a hole",
        "walls", "You see the faint outlines of a hole",
	"hole","A hole in the wall, promising more liquid",
   });
	dest_dir = ({ "/players/tatsuo/ezo/inner-yard1", "up", });
}

init() {
   ::init( );
   add_action("enter","enter");
}

enter(arg) {
   if ( arg != "hole" )
      return( 0 );
   TP->move_player( "out of sight#players/tatsuo/ezo/conn1" ); 
   return( 1 );
}    
