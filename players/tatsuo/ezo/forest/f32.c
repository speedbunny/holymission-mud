#define PPATH  "/players/tatsuo/ezo/forest/"
#define SPATH  "/players/tatsuo/ezo/coast/"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";

string upDir;

reset( arg )
{
   if ( arg )
      return;
      
   set_light( 0 );
      
   short_desc = "In a dark forest";
   long_desc = build_long_desc( );
   items = ({ "forest", long_desc,
              "ground", "It is that kind of ground you normally find in a forest",
              "trees", "The trees are very old and very big",
              "tree", "The tree is very old and very big",
              "eternity", "You cannot escape from it",
              "sky", "You cannot see the sky from here",
              "cliff", "The cliff is very steer and you can see a rock-ledge",
              "rock-ledge", "The rock-ledge is about 6 meters above the ground",
              });
              
   dest_dir = ({ PPATH + "f27", "north",
                 PPATH + "f28", "northeast",
                 PPATH + "f33", "east",
                 PPATH + "f31", "west",
                 PPATH + "f26", "northwest",
              });

   upDir = PPATH + "t32";
   
   smell = "Typical smell of a forest.";              
}


init( )
{
   ::init( );
   
   add_action( "search", "search" );
   add_action( "climb_it", "climb" );
}

search( arg )
{
   if ( !arg )
      return;
         
   write("You search and search, but find nothing special.\n");
   say(this_player()->query_name()+" searches around.\n");
   
   return( 1 );
}

climb_it( arg )
{
   if ( !arg || arg == "up" ) {
      write( "Climb what ?\n" );
      return( 1 );
   }
      
   if ( arg == "cliff" || arg == "rock-face" ) {
      write( "There are too much loose stones, so you cannot find a halt and fail.\n" );
      say( TPN + " tries to climb the cliff, but fails.\n" );
      return( 1 );
   }
   else if ( arg == "tree" )
   {
      if ( check_tekagi() ) {
         write( "You manage it to climb up with your tekagi.\n" );
         TP->move_player( "up the tree", upDir );
      }
      else {
         write( "You can't find a halt at the tree.\n" +
                "Maybe you need something which helps you climbing !?\n" );
         say( TPN + " tries to climb up the tree but fails.\n" );
      }
   
      return( 1 );
   }
   
   return( 0 );
}

build_long_desc( )
{
   string s;

   s = "You are in a really dark forest at the island of Ezo. You hardly can see\n" +
       "any further than to your nose. The trees here are all very big and very old.\n" +
       "To your south can you see a high cliff zooming up.\n";
   
   return( s );
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
