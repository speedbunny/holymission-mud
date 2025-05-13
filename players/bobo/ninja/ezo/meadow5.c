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
	"The ground here is grassy and there are flowers here.  To the\n"+
	"west is the eastern wall of a house.\n";
   items=({
	"meadow", long_desc,
        "hollow", long_desc,
	"ground","The ground is grassy and you can see some flowers",
	"grass","The grass has a fresh green color",
	"flowers","The flowers are very beautiful. Some of them are orchids",
	"flower","This flower is an orchid",
	"orchid","This is a @@flower_color@@ orchid",
	"orchids","The orchids are very pretty and have several colors",
	"wall","The wall is made of wood and looks very strong",
	"wood","It is teak",
	"sky","The sky is blue with a few clouds in it",
	"clouds","The clouds have a dirty white color",
   });
   smell = "You smell the odor of grass.";
   dest_dir=({
	PPATH + "meadow4","north",
	PPATH + "meadow21","northeast",
	PPATH + "meadow22","east",
	PPATH + "meadow23","southeast",
	PPATH + "meadow6","south",
   });
}

init() {
   ::init( );
   add_action( "get_it", "get" );
   add_action( "get_it", "take" );
   add_action( "get_it", "pick" );
}

get_it(arg) {
   if(!arg) return;
   if ( arg == "orchid" || arg == "orchids" ) {
      write( "Do you really want to destroy this beautiful orchid by picking it up ???\n" );
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
