inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  if (arg) return 0;

    set_light(1);
    short_desc = "Castle Gate";
    long_desc =
"You are at the draw-bridge of the great castle, Camelot, the\n"+
"legendary seat of the noble King Arthur.  Ahead of you is an open\n"+
"portcullis hanging from great chains.  The darkly vacant gate with\n"+
"the sharp points of the portcullis wavering above, make the scene \n"+
"look quite ominous... The castle itself is unfortunately looking in\n"+ 
"a very bad state at the moment... Perhaps the stories circulating\n"+ 
"about the King were true, after all...\n";

    dest_dir = ({
      "/players/emerald/perilous/path/black","south",
      CROOMS + "entrance", "north",
      TFOREST + "rm8", "east",
      TFOREST + "rm7", "west",
     });
    
    items = ({
    "portcullis",
  "The iron spikes of the portcullis swaying high above the ground look "+
  "sharp, depsite the obvious age of the gates themselves",
    "rope",
  "This is a coiled rope, leading over the Drawbridge, into the entrance "+
  "of the castle itself.  You presume it to be some mechanism for opening "+
  "the Bridge to the castle",
    "castle",
  "The sad absence of King Arthur, and his many Knights have meant that "+
  "Camelot has fallen into considerable disrepair in recent times",
    });

	clone_list = 
    ({ 2, 1, "bridge", "/players/tamina/castle/obj/bridge", 0, });

    ::reset();

    RPR("room/room");
}
