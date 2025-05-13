#include "../defs.h"

inherit GEN_GRAVE;

void reset( int arg ) {
  short_desc = "At an open grave with a black tomb stone.";
  long_desc = "You are standing in front of a hole in the ground, which "
    + "must once have contained a coffin. A big pile of sand is stacked "
    + "next to the hole. At the head of the grave stands a black granite "
    + "tomb stone.\n";
  hidden_dir = ({
    ROOM_DIR + "cemetry2", "north",
  });
  no_obvious_msg = "The gravel path lies directly north of this grave.\n";
  items=({
    "grave", "It's empty. You wonder if this is the work of grave robbers",
    "hole", "It has been dug quite a while ago. It must once have contained "
      + "a corpse",
    "ground", 
      "It's the same dark brown clay you saw in the tunnel in the hill",
    "pile", "It is half overgrown by weeds now",
    "weeds", 
      "You know, green plants that grow where you don't want them to..",
    "tomb stone", "In the black granite silver letters say: \"Boris the "
      + "Bloodthirsty R.I.P.\"",
  });
  property = "Boris";
  ::reset( arg );
  replace_program( GEN_GRAVE );
}
