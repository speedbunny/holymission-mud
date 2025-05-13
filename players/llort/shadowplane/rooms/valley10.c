inherit "/players/llort/shadowplane/shadowroom";
#include "/players/llort/shadowplane/room_defs.h"

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   short_desc = "Change of direction";
   long_desc =
      "The valley changes directions here. One way leads to the south,\n"+
      "and one leads west. Of course, everything is huddled in shadows\n"+
      "too in here.\n";

   dest_dir = ({ RPATH+"valley9", "south",
                 RPATH+"valley11", "west", });
}
