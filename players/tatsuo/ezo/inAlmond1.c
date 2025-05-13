#define PPATH  "/players/tatsuo/ezo/"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";
int    almondCount;
reset(arg) {
   object scroll;
   almondCount = 10;
   if ( !present( "bloodscroll", this_object() ) ) {
      scroll = clone_object( "/players/tatsuo/guild/nother/bloodscroll" );
      if ( transfer( scroll, this_object() ) )
         destruct( scroll );
   }
   if ( !present( "hudriwudri", this_object() ) )
      move_object( clone_object( "/players/tatsuo/eastMonst/hudriwudri" ),
                   this_object() );
   if(arg) return;
   set_light(1);
   short_desc = "In a almond tree";
   long_desc=
	"You are sitting on a big branch in the almond tree.  All around\n"+
	"you are green almond leaves.@@query_almond@@\n";
   items=({
	"tree", long_desc,
        "almond tree", long_desc,
        "ground", "The ground is grassy and you can see some flowers",
        "grass", "The grass has a fresh green color",
        "flowers", "The flowers are very beautiful. Some of them are orchids",
        "orchids", "The orchids are very pretty and have several colors",
        "wood", "It is almond, what else have you expected ?",
        "sky", "You cannot see the sky, because the leaves block your sight",
        "branch", "It is a very big branch and it looks stable",
        "leaves", "These are green almond leaves",
        "leave", "This is a green almond leave",
        "almond leaves", "These are green almond leaves",
        "almond leave", "This is a green almond leave",
              "almonds", "@@look_almonds@@",
              "almond", "@@look_almonds@@",
   });
   smell = "You smell the odor of almonds.";
}

init() {
   ::init( );
   add_action( "get_it", "get" );
   add_action( "get_it", "take" );
   add_action( "get_it", "pick" );
   add_action( "climb_it", "climb" );
   add_action( "climb_it", "down" );
}

get_it(arg) {
   object almond;
   if(!arg) return;
   if ( arg == "leave" || arg == "leaves" || arg == "almond leave"
	|| arg == "almond leaves" ) {
      write("You try to get an almond leave but it slips through your fingers.\n");
      return( 1 );
   }
   else if ( arg == "almonds" || arg == "almond" ) {
      if ( almondCount > 0 ) {
         almond = clone_object( "/players/tatsuo/guild/food/almond" );
         if ( transfer( almond, TP ) ) {
            write( "You can't take any more.\n" );
            destruct( almond );
         }
         else {
            write( "You pick a delicious-looking almond from the tree.\n" );
            say( TPN + " picks a delicious-looking almond from the tree.\n" );
         }
         almondCount--;
      }
      else
         write( "Do you see an almond here ?\n" );
      return( 1 );
   }
   return( 0 );
}

climb_it(arg) {
   if (!arg || arg == "down") {
      if ( !check_tekagi() ) {
         write("You don't find a halt at the tree and so you fall down. OUCH!\n");
         say( TPN + " doesn't find a halt at the tree and falls down.\n" );
         TP->hit_player( 10 );
      }
      TP->move_player( "down the tree#players/tatsuo/ezo/meadow22" );
      return( 1 );
   }
   write( "You only can climb down from here.\n" );
   return( 1 );
}

query_almond() {
   if ( almondCount > 0 )
      return( " Between the leaves you can see some almonds." );
      
   return( " " );
}

look_almonds() {
   if ( almondCount > 0 )
      return( "They look very delicious" );
  return( "You can't see any almonds here" );
}

check_tekagi() {
   int    i;
   for ( i = 0; i < sizeof(TP->query_armour()); i++ ) {
      if ( (TP->query_armour())[i] && (TP->query_armour())[i]->id( "tekagi" ) )
         return( 1 );
   }
   return( 0 );
}
