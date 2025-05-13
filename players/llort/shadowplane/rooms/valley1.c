inherit "/players/llort/shadowplane/shadowroom";
#include "/players/llort/shadowplane/room_defs.h"

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   short_desc = "Dead end";
   long_desc =
      "This seems to be a valley. Like all other rooms you cannot see\n"+
      "very much else than darkness and shadow around you. But you can\n"+
      "cleary recognize that this is a dead end the only exit is to the\n"+
      "west, leading into further shadows.\n";

   dest_dir = ({ RPATH+"valley2", "west" });
}
