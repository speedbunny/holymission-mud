inherit "/players/llort/shadowplane/shadowroom";
#include "/players/llort/shadowplane/room_defs.h"

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   short_desc = "Change of direction";
   long_desc =
      "The valley changes directions here. One way leads to the north,\n"+
      "and one leads east. Of course, everything is huddled in shadows\n"+
      "too in here. A strange thing is a nearly rotten tree-branch at the\n"+
      "ground. You wonder how any living thing can grow here ...\n";

   dest_dir = ({ RPATH+"valley11", "east",
                 RPATH+"valley8", "south", });

   items += ({"tree-branch","Nearly rotten, nothing special",
              "tree", "Nearly rotten, nothing special",
              "tree branch", "Nearly rotten, nothing special",
              "branch", "Nearly rotten, nothing special", });
}
