#include "../defs.h"

inherit GEN_GRAVE;

void reset( int arg ) {
  short_desc = "At an old grave surrounded by a small fence.";
  long_desc = "You find yourself at an old grave that is surrounded by a "
    + "small fence. The fence is made up from low, cubic stone blocks which "
    + "are interconnected by a rusty iron chain. A simple granite tomb "
    + "stone is placed at the head of the grave.\n";
  hidden_dir = ({
    ROOM_DIR + "cemetry5", "north",
  });
  no_obvious_msg = "The gravel path lies directly north of this grave.\n";
  items=({
    "grave", "Although completely covered in weeds, the grave seems to be "
      + "quite intact",
    "weeds", "An uninviting patch of stinging nettles grows on the grave",
    "fence", "A fence of stone blocks and chains sets this grave apart from "
      + "the rest",
    "blocks", "Made up of bricks, someone etched a message on one of them",
    "chain", 
      "It's badly rusted. Only its thickness has prevented it from breaking",
    "message", "......mpi.es ..e ver. dan..ro.s . . . . . .",
    "tomb stone", "A plain black stone with the words \"Andrevitsh R.I.P.\"",
  });
  property = "Andrevitch";
  ::reset( arg );
  replace_program( GEN_GRAVE );
}
