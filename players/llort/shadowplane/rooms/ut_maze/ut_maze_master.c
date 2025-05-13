#include "/players/llort/shadowplane/rooms/ut_maze/ut_maze.h"

mixed mtx;

void reset( int tick )
{
   int i, j;

   if ( tick ) return;

   mtx = allocate( MAZE_EXT_HORI );
   for ( i = 0; i < MAZE_EXT_HORI; i++ ) {
      mtx[i] = allocate( MAZE_EXT_VERT );
      for ( j = 0; j < MAZE_EXT_VERT; j++ )
         mtx[i][j] = 0;
   }
}

object get_room( int x, int y )
{
   if ( mtx[x][y] == 0 ) {
      mtx[x][y] = clone_object( UT_MAZE_ROOM );
      (mtx[x][y])->set_koord(x,y);
   }
   return( mtx[x][y] );
}
