inherit "/players/llort/shadowplane/shadowroom";
#include "/players/llort/shadowplane/room_defs.h"
#include "/players/llort/shadowplane/rooms/ut_maze/ut_maze.h"

#define EXIT1  RPATH+"underTrunk8"
#define EXIT2  RPATH+"behindMaze1"

int xPos, yPos;

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   short_desc = "In a VERY dark cave";
   long_desc =
      "You are in a VERY dark cave. You hardly can see your hand before\n"+
      "your eyes and shadows are all around in the room. The shadows seem\n"+
      "to be shadows of the darkness, or at last you cannot decide of what\n"+
      "they could be the shadows. You feel completely lost in here and have\n"+
      "absolute no sense of direction anymore ...\n";

   items += ({ "cave", "VERY dark",
               "shadows", "They are dark",
               "shadow", "Dark, very dark",
               "darkness", "What do you suppose it looks like .." });
}

void long( string str )
{
   if ( TP->query_real_name() == "patience" )
      write( "x = "+xPos+" y = "+yPos+"\n" );
   ::long(str);
}

init()
{
   ::init();

   add_action( "do_move", "west" );
   add_action( "do_move", "east" );
   add_action( "do_move", "north" );
   add_action( "do_move", "south" );
}

int do_move( string arg )
{
   object room;
   string verb;
   int    turn, rind;

   if ( arg && arg != "" )
      return( 0 );

   room = 0;
   verb = query_verb();
   turn = (yPos * MAZE_EXT_HORI + xPos) % 4;
   rind = member_array( verb, DIR ); 
   verb = WWI[turn + rind];

   // ----- NORTH --------------
   if ( verb == "north" ) {
      if ( yPos > 0 ) {
         room = UT_MAZE_MASTER->get_room(xPos,yPos-1);
      }
   }
   // ----- EAST ---------------
   else if ( verb == "east" ) {
      if ( xPos < MAZE_EXT_HORI-1 ) {
         room = UT_MAZE_MASTER->get_room(xPos+1,yPos);
      }
   }
   // ----- SOUTH ---------------
   else if ( verb == "south" ) {
      if ( yPos < MAZE_EXT_VERT-1 ) {
         room = UT_MAZE_MASTER->get_room(xPos,yPos+1);
      }
      else if ( xPos == MAZE_EXT_HORI-2 && yPos == MAZE_EXT_VERT-1 ) {
         call_other( EXIT1, "???" );
         room = find_object( EXIT1 );
      }
   }
   // ----- WEST ---------------
   else if ( verb == "west" ) {
      if ( xPos > 0 ) {
         room = UT_MAZE_MASTER->get_room(xPos-1,yPos);
      }
      else if ( xPos == 0 && yPos == 1 ) {
         call_other( EXIT2, "???" );
         room = find_object( EXIT2 );
      }
   }

   if ( !room )
      write( "BOING !!!! There must be a wall or something !\n" );
   else
      TP->move_player( verb+"#"+file_name(room) );

   return( 1 );
}

void set_koord( int x, int y )
{
   xPos = x;
   yPos = y;
}
