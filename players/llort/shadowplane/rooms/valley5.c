inherit "/players/llort/shadowplane/shadowroom";
#include "/players/llort/shadowplane/room_defs.h"

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   short_desc = "Fork";
   long_desc =
      "You are wandering along a huge valley. But the valley forks here,\n"+
      "with pathes leading to the north, east and west. You cannot see\n"+
      "very far into each valley, all is hidden behind shadows. The only\n"+
      "think you are sure of is the wall to the south.\n";

   dest_dir = ({ RPATH+"valley9", "north",
                 RPATH+"valley4", "east",
                 RPATH+"valley6", "west", });
}
