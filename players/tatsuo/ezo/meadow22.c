#define PPATH  "/players/tatsuo/ezo/"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define TO     (this_object())

inherit "room/room";
int treeShaked;
reset(arg) {
   treeShaked = 0;
  if(!present("pepper",this_object())){
 transfer(clone_object("/players/tatsuo/guild/nother/red_pepper"),this_object() );
 transfer(clone_object("/players/tatsuo/guild/nother/red_pepper"),this_object() );
 transfer(clone_object("/players/tatsuo/guild/nother/red_pepper"),this_object() );
 transfer(clone_object("/players/tatsuo/guild/nother/red_pepper"),this_object() );
 transfer(clone_object("/players/tatsuo/guild/nother/red_pepper"),this_object() );
 transfer(clone_object("/players/tatsuo/guild/nother/red_pepper"),this_object() );
 transfer(clone_object("/players/tatsuo/guild/nother/red_pepper"),this_object() );
 transfer(clone_object("/players/tatsuo/guild/nother/red_pepper"),this_object() );
 transfer(clone_object("/players/tatsuo/guild/nother/red_pepper"),this_object() );
 transfer(clone_object("/players/tatsuo/guild/nother/red_pepper"),this_object() );
 transfer(clone_object("/players/tatsuo/guild/nother/red_pepper"),this_object() );
 transfer(clone_object("/players/tatsuo/guild/nother/red_pepper"),this_object() );
}
   if (arg) return;
   set_light(1);
   short_desc = "In a meadow";
   long_desc=
	"You are standing in a meadow in a hollow of the island of Ezo.\n"+
        "The ground here is grassy and there are flowers here. To the\n" +
        "southeast is the rock face of the volcano crater. There is an\n" +
       "ALMOND TREE here.  A patch of spicy red peppers grow here.\n";
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
        "eternity", "You cannot escape from it",
        "sky", "The sky is blue with a few clouds on it",
        "clouds", "The clouds have a dirty white color",
        "crater","You're inside the crater. Just look around to see more of it",
	"volcano crater","You're in the crater, just look around you",
	"volcano","Youre inside the crater, just look around you to see more",
        "almond tree", "It is a typical almond-tree",
        "tree", "It is a typical almond tree",
   });
   smell = "You smell the odor of grass and almonds.";
   dest_dir=({
	PPATH + "meadow21","north",
        PPATH + "meadow33", "northeast",
        PPATH + "meadow34", "east",
        PPATH + "meadow23", "south",
        PPATH + "meadow6",  "southwest",
        PPATH + "meadow5",  "west",
        PPATH + "meadow4",  "northwest",
   });
}

init() {
   ::init( );
   add_action( "get_it", "get" );
   add_action( "get_it", "take" );
   add_action( "get_it", "pick" );
   add_action( "climb_it", "climb" );
   add_action( "shake_it", "shake" );
}

get_it(arg) {
   object almond;
   if(!arg) return;
   if ( arg == "orchid" || arg == "orchids" ) {
      write( "Do you really want to destroy this beautiful orchid by picking it up ???\n" );
      return( 1 );
   }
   if ( arg == "almond" || arg == "almonds" ) {
      almond = present( "almond", TO );
      if ( !almond )
         write( "Do you see any almonds here ?\n" );
      else {
         if ( transfer( almond, TP ) )
            write( "You cannot take any more.\n" );
         else
            write( "Ok.\n" );
      }
      return( 1 );
   }
   return( 0 );
}

climb_it(arg) {
  object tekagi;
   if ( arg == "rock face" || arg == "crater" || arg == "volcano crater" ||
        arg == "volcano" )
   {
      write( "The rock-face is much too steep to climb it.\n" );
      say( TPN + " tries to climb the rock-face, but fails.\n" );
      return( 1 );
   }
   else if ( arg == "wall" ) {
      write( "Do you see a wall here ?\n" );
      return( 1 );
   }
   else if ( arg == "tree" || arg == "almond-tree" ) {
      if ( check_tekagi() )
         this_player()->move_player( "up the tree#players/tatsuo/ezo/inAlmond1" );
      else {
         write( "You can't find a halt at the massive tree and so you fail.\n" );
         say( TPN + " tries to climb up the tree but fails.\n" );
      }
      return( 1 );
   }
   return( 0 );
}

shake_it(arg) {
   object almond;
   int    i, high;
  if(!arg) return 0;
   if ( arg == "tree" || arg == "almond-tree" ) {
      if ( treeShaked ) {
         write( "You shake the almond-tree, but nothing happens.\n" );
         say( TPN + " shakes the almond-tree.\n" );
      }
      else {
         write( "As you shake the almond-tree, some almonds falling onto your head. OUCH !!\n" );
         say( TPN + " shakes the almond-tree and some almonds falling onto your head. OUCH !!\n" );
         treeShaked = 1;
         high = random( 4 ) + 2;
         for ( i = 0; i < high; i++ ) {
            almond = clone_object( "/players/tatsuo/guild/food/almond" );
            transfer( almond, TO );
         }
      }
      return( 1 );
   }
   return( 0 );
}

flower_color() {
   switch(randome(6)) {
      case 0: return( "blue" );
      case 1: return( "white" );
      case 2: return( "red sprinkled" );
      case 3: return( "red" );
      case 4: return( "rotten" );
      default: return( "light yellow" );
   }
   return( "red" );
}

check_tekagi( )
{
   int    i;

   for ( i = 0; i < sizeof(TP->query_armour()); i++ ) {
      if ( (TP->query_armour())[i] && (TP->query_armour())[i]->id( "tekagi" ) )
         return( 1 );
   }

   return( 0 );
}
