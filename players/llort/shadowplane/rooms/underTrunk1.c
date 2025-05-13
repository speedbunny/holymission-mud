inherit "/players/llort/shadowplane/shadowroom";
#include "/players/llort/shadowplane/room_defs.h"

#define CONN (RPATH+"valley7")

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   short_desc = "In a dark cave";
   long_desc =
      "You are in a narrow, dark cave. The walls seem to suppress you, but\n"+
      "at least you can see the walls clearly. The material, the walls are\n"+
      "made of, is soft to the touch, but none you can find on the prime\n"+
      "material plane. A liquid is dropping down from the ceiling right onto\n"+
      "your head .... drop .... drop .... drop ..... annoying !\n@@csl@@";

   items += ({ "liquid","You don't know this liquid. It is red",
               "ceiling","@@csi@@",
               "walls","They are soft to the touch",
               "wall","It is soft to the touch",
               "material","It is very strange" });
  
   dest_dir = ({ RPATH+"underTrunk2", "north" });
}

void init()
{
   ::init();

   add_action( "do_enter", "enter" );
   add_action( "do_touch", "touch" );
}

string csl( )
{
   if ( CONN->is_open() )
      return( "There is crack in the ceiling, big enough to enter !\n" );
   return( "" );
}

string csi( )
{
   if ( CONN->is_open() )
      return( "There is an opening in the ceiling" );
   return( "There is a huge crack in the ceiling, almost hidden by shadows" );
}

int do_enter( string arg )
{
   if ( arg != "crack" )
      return( 0 );

   CONN->open();
   TP->move_player( "up#"+CONN );
   return( 1 );
}

int do_touch( string arg )
{
   if ( arg != "wall" && arg != "ceiling" )
      return( 0 );

   write( "You touch the "+arg+".\n" );
   say( TPN + " touches the "+arg+".\n" );
   return( 1 );
}
