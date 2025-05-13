inherit "/players/llort/shadowplane/shadowroom";
#include "/players/llort/shadowplane/room_defs.h"
#include "/players/llort/shadowplane/rooms/ut_maze/ut_maze.h"

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   short_desc = "Finally out !";
   long_desc =
      "You are finally out of this maze !!! But has anything changed !?\n" +
      "The area is still very dark in here and you are in a tunnel again.\n"+
      "From the west you can sense danger in some form and to the east is\n"+
      "the VERY dark area ...\n";

   dest_dir = ({ RPATH+"behindMaze2", "west" });
}

init()
{
   ::init();

   add_action( "do_touch", "touch" );
   add_action( "do_east", "east" );
}

int do_touch( string arg )
{
   if ( arg != "wall" && arg != "ceiling" )
      return( 0 );

   write( "You touch the "+arg+".\n" );
   say( TPN + " touches the "+arg+".\n" );
   return( 1 );
}

int do_east( string arg )
{
   object room;

   if ( arg ) return( 0 );

   room = UT_MAZE_MASTER->get_room( 0, 1 );
   if ( room )
      TP->move_player( "east#"+file_name(room) );
   else                                                // BUG !!!
      write( "Somehow you do not manage it to go east from here !\n" );
   return( 1 );
}
