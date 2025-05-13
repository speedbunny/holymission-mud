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
	"You are standing in a meadow in a hollow of the island of Ezo.\n"+
	"The ground ehre is grassy and there are flowers here.  To the\n"+
	"southwest is the mortheastern corner of a house and the to the\n"+
	"northeast is the rock face of the volcano crater.\n";
   items=({
	"meadow", long_desc,
	"hollow", long_desc,
	"ground","The groudn is grassy and you can see some flowers",
	"grass","The grass has a fresh green color",
	"flowers","The flowers are very beautiful. some of them are orchids",
	"flower","This flower is an orchid",
	"orchid","This is a @@flower_color@@ orchid",
	"orchids","The orchids are very pretty and have several colors",
	"corner","It is the northeastern corner of the wall",
	"wall","The wall is made of wood and looks very strong",
	"wood","It is teak",
	"rock-face","You think, that the rock-face extends almost to eternity",
	"eternity","You cannot escape from it",
	"sky","The sky is blue with a few clouds in it",
	"clouds","The clouds have a dirty white color",
	"crater","You're inside the crater. Just look around to see more of it",
	"volcano-crater","You're in the crater, just look around to see more",
	"volcano","You are inside the crater. Just look around to see more",
   });
   smell = "You smell the odor of grass.";
   dest_dir=({
	PPATH + "meadow19","north",
	PPATH + "meadow20","east",
	PPATH + "meadow21","southeast",
	PPATH + "meadow4","south",
	PPATH + "meadow2","west",
	PPATH + "meadow18","northwest",
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
   if(arg) return;
   if ( arg == "orchid" || arg == "orchids" ) {
      write( "Do you really want to destroy this beautiful orchid by picking it up ???\n" );
      return( 1 );
   }
   return( 0 );
}

climb_it(arg) {
   if(!arg) return;
   if ( arg == "rock-face" || arg == "crater" || arg == "volcano-crater" ||
        arg == "volcano" ) {
      write( "The rock-face is much too steep to climb it.\n" );
      say( TPN + " tries to climb the rock-face, but fails.\n" );
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
