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
	"You are standing on a meadow in a hollow of the island of Ezo.\n"+
	"The ground here is grassy and there are flowers here.  To the\n"+
	"south is the northern wall of a house.\n";
   items=({
	"meadow", long_desc,
	"hollow", long_desc,
	"ground","The ground is grassy and you can see some flowers",
	"grass","The grass has a fresh green color",
	"flowers","The flowers are very beautigul. Some of them are orchids",
	"flower","This flower is an orchid",
	"orchid","this is a @@flower_color@@ orchid",
	"orchids","The orchids are very pretty and hace several colors",
	"wall","the wall is made of wood and looks very strong",
	"wood","It is teak",
	"sky","The sky is blue with a few clouds in it",
	"clouds","The clouds have a dirty white color",
	"crater","You're inside the crater. Just look around to see more of it",
	"volcano-crater","You're in the crater, just look around to see it",
	"volcano","You're in the crater, just look around to see more of it",
   });
   smell = "You smell the odor of grass.";
   
   dest_dir=({
	PPATH + "meadow18","north",
	PPATH + "meadow19","northeast",
	PPATH + "meadow3","east",
	PPATH + "meadow1","west",
	PPATH + "meadow17","northwest",
   });
}

init() {
   ::init( );
   add_action( "get_it", "get" );
   add_action( "get_it", "take" );
   add_action( "get_it", "pick" );
   add_action( "climb_it", "climb" );
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
   if ( arg == "rock-face" || arg == "crater" || arg == "volcano-crater" ||
        arg == "volcano" )
   {
      write( "Do you see a rock-face here ?\n" );
      return( 1 );
   }
   else if ( arg == "wall" ) {
      write( "The wall is much too smooth to climb it.\n" );
      say( TPN + " tries to climb the wall, but fails.\n" );
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
