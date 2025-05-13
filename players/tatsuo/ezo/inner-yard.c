#define PPATH "/players/tatsuo/ezo/"
#define TP  this_player()
#define TPN TP->query_name()

inherit "room/room";
object ninja;
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "At the inner yard";
   long_desc=
	"This is the inner yard of the residence of Matsumae Yoshihiro,\n"+
	"the evil Shogun of the island of Ezo. The ground here consists of\n"+
	"mostly grass. to the east and the west are chambers of the\n"+
	"residence, the north is the entrance to this yard, and to the\n"+
	"yard continues onward to the south.\n";
   items= ({
	"inner yard", long_desc,
        "yard", long_desc,
        "ground", "The ground is grassy",
        "grass", "It is almosted stamped down but it has a fresh green color",
	"chambers","These are the chambers of Yoshihiro's house",
	"chamber","This is one of the many chambers of Yoshihiro's house",
        "entrance", "This is the entrance to the yard",
   });
   dest_dir=({
	PPATH + "entrance","north",
      PPATH +"empty","east",
    PPATH +"bar","west",
	PPATH + "inner-yard1","south",
   });
}

init() {
   ::init( );
   add_action("enter","enter");
}

west() {
   if ( TP->query_guild() != 8 && TP->query_level() > 9991 &&
         !TP->query_immortal()) {
      if ( ninja ) {
         write( "The ninja hinders you from entering the chamber !!!\n" );
      }
      else {
         write( "Suddenly a ninja appears and yawns tiredly.\n" +
                "The ninja says: Leave me alone.... \n" +
		"The ninja goes back to sleep. \n" );
         }
      }
     write( "You are allowed to enter there.\n" );
      return( 0 );
   this_player()->move_player( "west#players/tatsuo/ezo/bar" );
   return( 1 );
}

east() {
   if ( TP->query_guild() != 8 && TP->query_level() > 99991 ) {
      if ( ninja ) {
         write( "The ninja hinders you from entering the chamber !!!\n" );
      }
      else {
         write( "Suddenly a ninja appears and yawns tiredly.\n" +
                "The ninja says: Today is my free day ! \n" +
		"The ninja goes back to play go-bang.\n" );
      }
      write( "You are allowed to enter there.\n" );
      return( 1 );
   }
   this_player()->move_player( "east#players/tatsuo/ezo/empty" );
   return( 1 );
}

enter(arg) {
   if(arg)  return;
   write( "Give a direction to enter one of the chambers.\n" );
   return( 1 );
}    
