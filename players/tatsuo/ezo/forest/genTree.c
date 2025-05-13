#define PPATH  "/players/tatsuo/ezo/forest/"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

#define BARK   "/players/tatsuo/guild/nother/birch_bark"

inherit "room/room";

string downDir;
int    barkIsHere;

reset( arg )
{
   barkIsHere = 1;

   if ( arg )
      return;
      
   set_light(1);
   short_desc = "In a tree";
   long_desc = "You are sitting on a big branch in a birch-tree. All around\n" +
               "you are fresh green leaves. The leaves are so dense, that you\n" +
               "hardly can see more then leaves.\n";
   items = ({ "tree", long_desc,
              "sky", "You cannot see the sky, because the leaves block your sight",
              "branch", "It is a very big branch and it looks stable",
              "leaves", "These are fresh green leaves",
              "leave", "This is a fresh green leave",
              });
   
   smell = "You smell the odor of leaves.";
}


init( )
{
   ::init( );
   
   add_action( "search", "search" );
   
   add_action( "climb_it", "climb" );
   add_action( "climb_it", "down" );
   add_action( "jump_it",  "jump" );
   add_action( "tear_off", "tear" );
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

tear_off( arg )
{
   object bark;

   if ( !arg )
      return;

   if ( arg == "bark" || arg == "off bark" || arg == "off some bark" ) {
      if ( !barkIsHere ) {
         write( "You cannot see a loose piece of bark, maybe someone was quicker.\n" );
         return( 1 );
      }
      
      write( "You tear of a piece of bark from the tree.\n" );
      say( this_player()->query_name() + " tears of a piece of bark.\n" );
      
      bark = clone_object( BARK );
      if ( transfer( bark, this_player() ) ) {
         write( "But it is too heavy for you, so you drop it.\n" );
         transfer( bark, this_object() );
         barkIsHere = 0;
      }
      
      return( 1 );
   }
}

jump_it( arg )
{
   if ( !arg ) {
      write( "You jump around for a while but then feel silly and you decide to stop it.\n" );
      say( TP->query_name() + " jumps around.\n" );
   }
   else {
      write( "You try to jump away from the branch. But you slide off and fall down. OUCH !!\n" );
      TP->move_player( "down the tree", downDir );
   }
   
   return( 1 );
}

set_down_dir( s )
{
   downDir = s;
}

query_down_dir( )
{
   return( downDir );
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
