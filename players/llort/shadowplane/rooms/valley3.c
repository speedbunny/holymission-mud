inherit "/players/llort/shadowplane/shadowroom";
#include "/players/llort/shadowplane/room_defs.h"

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   short_desc = "Valley";
   long_desc =
      "You are wandering along a huge valley. Faintly visible are walls\n"+
      "to the north and to the south, but they are nearly hidden behind\n"+
      "all these shadows. It seems that there is nothing else than shadows\n"+
      "in this plane ...\n";

   dest_dir = ({ RPATH+"valley2", "east",
                 RPATH+"valley4", "west", });
}
