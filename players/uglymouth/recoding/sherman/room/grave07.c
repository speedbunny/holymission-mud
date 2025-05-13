#include "../defs.h"

inherit GEN_GRAVE;

void reset( int arg ) {
  short_desc = "At a grave with a circular tomb stone.";
  long_desc = "The grave you are standing next to has a somewhat remarkable "
    + "tomb stone at its head. A stone disk ten centimeters thick has been "
    + "places for one quarter in the ground. An epitaph is written on it "
    + "spiralling inward.\n";
  hidden_dir = ({
    ROOM_DIR + "cemetry5", "south",
  });
  no_obvious_msg = "The gravel path lies directly south of this grave.\n";
  items=({
    "grave", "This grave looks intact and has been used over for growing "
      + "weeds only a little",
    "weeds", "Dandelions seem to dominate all other plants on this grave",
    "tomb stone", "It is perfectly circular in shape, even though it's "
      + "battered by the winds",
    "epitaph", "It reads: \"Here rests Drago not in piece because he stole "
      + "money from a mage\"",
  });
  property = "Drago";
  ::reset( arg );
  replace_program( GEN_GRAVE );
}
