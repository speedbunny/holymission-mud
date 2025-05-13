#define PPATH  "/players/tatsuo/ezo/forest/"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";

string downDir, jumpDir;

reset( arg )
{
   if ( arg )
      return;
      
   set_light(1);
   short_desc = "In a tree";
   long_desc = "You are sitting on a big branch in a tree. All around you\n" +
               "are fresh green leaves. But the leaves are a bit lighter here\n" +
               "and so you can see a rock-ledge to the south.\n";
   items = ({ "tree", long_desc,
              "sky", "You cannot see the sky, because the leaves block your sight",
              "branch", "It is a very big branch and it looks stable",
              "leaves", "These are fresh green leaves",
              "leave", "This is a fresh green leave",
              "rock-ledge", "The rock-ledge is nearly at your height",
              });
              
   downDir = PPATH + "f33";
   jumpDir = PPATH + "rl5";
   
   smell = "You smell the odor of leaves.";
}


init( )
{
   ::init( );
   
   add_action( "search", "search" );
   
   add_action( "climb_it", "climb" );
   add_action( "climb_it", "down" );
   add_action( "jump_it",  "jump" );
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
   if ( !arg || arg == "down" )
   {
      if ( !check_tekagi() ) {
         write( "You don't find a halt at the tree and so you fall down. OUCH !!\n" );
         say( TPN + " doesn't find a halt at the tree and fells down.\n" );
         TP->hit_player( 10 );
      }
      TP->move_player( "down the tree", downDir );
      return( 1 );
   }
   
   write( "You only can climb down from here.\n" );
   return( 1 );
}

jump_it( arg )
{
   if ( !arg ) {
      write( "You jump around for a while but then feel silly and you decide to stop it.\n" );
      say( TP->query_name() + " jumps around.\n" );
   }
   else if ( arg == "rock-ledge" || arg == "to rock-ledge" || arg == "onto rock-ledge" ||
             arg == "at rock-ledge" || arg == "ledge" || arg == "to ledge" ||
             arg == "onto ledge" || arg == "at ledge" )
   {
      write( "You summon all your powers and make a big jump to the rock-ledge !!!\n" );
      TP->move_player( "to the rock-ledge", jumpDir );
   }
   else {
      write( "You try to jump away from the branch. But you slide off and fall down. OUCH !!\n" );
      TP->move_player( "down the tree", downDir );
   }
   
   return( 1 );
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
