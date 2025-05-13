#define PPATH  "/players/tatsuo/ezo/"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "At a meadow";
   long_desc=
	"You are standing on a meadow in a hollow of the island of Ezo.\n"+
	"The ground here is grassy and there are flowers here.  To the\n"+
        "southeast, southwest, and west is the rock-face of the volcano\n"+
	"crater. A path leads south between the two rock walls.\n";
   items=({
	"meadow", long_desc,
	"hollow", long_desc,
	"flower","This flower is an orchid",
	"flowers","The flowers are very beautiful. Some of them are orchids",
	"orchid","This is a @@flower_color@@ orchid",
	"orchids","The orchids are very pretty and have several colors",
	"rock face","You think that the rock face extends almost to eternity",
	"eternity","You cannot escape from it",
	"sky","The sky is blue with a few clouds in it",
	"clouds","The clouds have a dirty white color",
	"crater","You're inside the crater. Just look around to see more of it",
	"volcano crater","You're in the crater, just lok around to see more",
	"ground","The ground is grassy and you can see some flowers",
	"volcano","You're in the crater. Just look around to see more",
   });
   smell = "You smell the odor of grass.";
   dest_dir=({
	PPATH + "meadow10","north",
	PPATH + "meadow9","northeast",
	PPATH + "meadow25","east",
	PPATH + "meadow11","northwest",
   });
              
}

init () {
   ::init( );
   add_action( "get_it", "get" );
   add_action( "get_it", "take" );
   add_action( "get_it", "pick" );
   add_action( "climb_it", "climb" );
}

get_it (arg) {
   if(!arg) return;
   if ( arg == "orchid" || arg == "orchids" ) {
      write( "Do you really want to destroy this beautiful orchid by picking it up ???\n" );
      return( 1 );
   }
   return( 0 );
}

climb_it(arg) {
   if(!arg) return;
   if ( arg == "rock face" || arg == "crater" || arg == "volcano crater" ||
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

flower_color() {
   switch(random(6)) {
      case 0: return( "blue" );
      case 1: return( "white" );
      case 2: return( "red sprinkled" );
      case 3: return( "red" );
      case 4: return( "rotten" );
      default: return( "light yellow" );
   }

   return( "red" );
}
