inherit "/players/llort/shadowplane/shadowroom";
#include "/players/llort/shadowplane/room_defs.h"
#include "/players/llort/shadowplane/rooms/ut_maze/ut_maze.h"

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   short_desc = "In a cave";
   long_desc =
      "You are in a narrow, dark cave. The walls seem to suppress you, but\n"+
      "at least you can see the walls clearly. The material, the walls are\n"+
      "made of, is soft to the touch, but none you can find on the prime\n"+
      "material plane. A liquid is dropping down from the ceiling right onto\n"+
      "your head .... drop .... drop .... drop ..... annoying !\n"+
   "To the north is an area of complete darkness, looking very dangerous !!!\n";

   items += ({ "liquid","You don't know this liquid. It is red",
               "ceiling","It is soft to the touch",
               "walls","They are soft to the touch",
               "wall","It is soft to the touch",
               "material","It is very strange" });
  
   dest_dir = ({ RPATH+"underTrunk7", "south" });
}

void init()
{
   ::init();

   add_action( "do_touch", "touch" );
   add_action( "do_north", "north" );
}

int do_touch( string arg )
{
   if ( arg != "wall" && arg != "ceiling" )
      return( 0 );

   write( "You touch the "+arg+".\n" );
   say( TPN + " touches the "+arg+".\n" );
   return( 1 );
}

int do_north( string arg )
{
   object room;

   if ( arg ) return( 0 );

   room = UT_MAZE_MASTER->get_room( MAZE_EXT_HORI-2,MAZE_EXT_VERT-1 );
   if ( room )
      TP->move_player( "north#"+file_name(room) );
   else                                                // BUG !!!
      write( "Somehow you do not manage it to go north from here !\n" );
   return( 1 );
}
