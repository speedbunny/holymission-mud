#define PPATH  "/players/tatsuo/ezo/"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "In a meadow";
   long_desc=
	"You are standing in a meadow in a hollow of the island of Ezo.\n"+
	"The ground here is grassy and there are flowers here. To the\n"+
	"southwest, west, and northwest is the rock face of the volcano\n"+
	"There is a narrow and dark hole in the rock face.\n";
   items=({
	"meadow", long_desc,
        "hollow", long_desc,
        "ground", "The ground is grassy and you can see some flowers",
        "grass", "The grass has a fresh green color",
        "flowers", "The flowers are very beautiful. Some of them are orchids",
        "flower", "This flower is an orchid",
        "orchid", "This is a @@flower_color@@ orchid",
        "orchids", "The orchids are very pretty and have several colors",
	"rock face","You think that the rock face extends almost to eternity",
	"hole","It is a narrow and dark hole with an evil aura",
        "eternity", "You cannot escape from it",
        "sky", "The sky is blue with a few clouds on it",
        "clouds", "The clouds have a dirty white color",
        "crater","You're inside the crater. Just look around to see more of it",
	"volcano crater","You're in the crater. Just look around to see more",
	"volcano","You're inside the crater, just look around to see more",
});
   smell = "You smell the odor of grass.";
   dest_dir=({
	PPATH + "meadow30","north",
        PPATH + "meadow15", "northeast",
        PPATH + "meadow14", "east",
        PPATH + "meadow13", "southeast",
        PPATH + "meadow28", "south",
   });
}

init() {
   ::init( );
   add_action( "get_it", "get" );
   add_action( "get_it", "take" );
   add_action( "get_it", "pick" );
   add_action( "climb_it", "climb" );
   add_action( "enter_it", "enter" );
}

get_it(arg) {
   if(!arg) return;
   if ( arg == "orchid" || arg == "orchids" ) {
      write( "Do you really want to destroy this beautiful orchid by picking it up ???\n" );
      return( 1 );
   }
   return( 0 );
}

climb_it(arg) {
   if(!arg) return;
   if ( arg == "ro ck face" || arg == "crater" || arg == "volcano-crater" ||
	arg == "volcano" ) {
      write( "The rock-face is much too steep to climb it.\n" );
      say( TPN + " tries to climb the rock-face, but fails.\n" );
      return( 1 );
   }
   else if ( arg == "wall" ) {
      write( "Do you see a wall here ?\n" );
      return( 1 );
   }
   return( 0 );
}

enter_it(arg) {
   if(!arg) return;
   if ( arg == "hole" || arg == "dark hole" || arg == "narrow and dark hole" ) {
      TP->move_player( "into the hole#players/tatsuo/ezo/cave/cave16" );
      return( 1 );
   }
   return( 0 );
}

flower_color() {
   switch(random(6)) {
      case 0: return( "blue" );
      case 1: return( "white" );
      case 2: return( "red sprinkled" );
      case 3: return( "red" );
      case 4: return( "rotten" );
      default: return( "light yellow" );
   }
   return("red");
}
