#define PPATH  "/players/tatsuo/ezo/"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";
object *ob;
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "At a meadow";
   long_desc=
	"You are standing on a meadow in a hollow of the island of Ezo.\n"+
	"The ground here is grassy and there are flowers here. To the south\n"+
	"is the entrance to the residence of the evil Shogun of the island.\n"+
	"Over the entrance you can see an inscription scratched in the wall.\n"+
	"Do NOT go south if you value your life !\n";
   items=({
	"meadow", long_desc,
	"hollow", long_desc,
	"ground","The ground is grassy and you can see some flowers",
	"grass","The grass has a fresh green color",
	"flowers","The flowers are very beautiful. some of them are orchids",
	"flower","This flower is an orchid",
	"orchid","This is a @@flower_color@@ orchid",
	"orchids","The orchids are very pretty and have several colors",
	"entrance","It is the entrance to the residence of the evil Shogun of Ezo.\n"+
                   "the house has a demonic aura and you think you don't want to\n"+
                   "enter it at all",
	"inscription","The inscription is scratched into the wall and painted out with blood",
	"sky","The sky is blue with a few clouds in it",
	"clouds","The clouds have a dirty white color",
	"crater","You're inside the crater. Just look around to see more of it",
        "volcano crater","You're inside it, just look around to see more of it",
	"volcano","You're in the crater, just look around to see more of it",
   });
   smell = "You smell the odor of blood.";
   dest_dir=({
	PPATH + "meadow17","north",
	PPATH + "meadow18","northeast",
	PPATH + "meadow2","east",
	PPATH + "entrance","south",
	PPATH + "meadow16","west",
	PPATH + "meadow32","northwest",
   });
}

init () {
   ::init( );
   add_action( "read_it", "read" );
   add_action( "get_it", "get" );
   add_action( "get_it", "take" );
   add_action( "get_it", "pick" );
}

read_it(arg) {
   if(!arg) return;
   if ( arg == "inscription" ) {
      write( "The inscription says: IF YOU DON'T HAVE A GOOD REASON TO ENTER, KEEP OUT !!!\n" );
      return( 1 );
   }
   return( 0 );
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
