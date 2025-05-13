#include "../defs.h"

inherit GEN_GRAVE;

void reset( int arg ) {
  short_desc = "At a bare grave with the remains of a wooden cross.";
  long_desc = "You stand next to what you would call a fresh grave, if not "
    + "for the fact that it has been this way for so long. Obviously the "
    + "curse fell over these lands soon after this person who's buried here "
    + "died. A rotten wooden cross heads at the grave.\n";
  hidden_dir = ({
    ROOM_DIR + "cemetry3", "north",
  });
  no_obvious_msg = "The gravel path lies directly north of this grave.\n";
  items=({
    "grave", 
      "A patch of the same dark brown clay, halfway overgrown with weeds",
    "weeds", "Sticking nettles, dandelions and moss make up the vegetation "
      + "on this grave",
    "cross", "It has rotten away for the most part. You can still read "
      + "\".icolai R.\"",
  });
  property = "Nicolai";
  ::reset( arg );
  replace_program( GEN_GRAVE );
}
