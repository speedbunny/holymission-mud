#include "../defs.h"

inherit GEN_GRAVE;

void reset( int arg ) {
  short_desc = "At a grave with a fallen tomb stone.";
  long_desc = "You are standing next to a grave with its tomb stone fallen "
    + "down on it. Moss has covered all of the grey stone in a dark green "
    + "sheet.\n";
  hidden_dir = ({
    ROOM_DIR + "cemetry3", "south",
  });
  no_obvious_msg = "The gravel path lies directly south of this grave.\n";
  items=({
    "grave", "An old grave. Noone has taken care of it for ages",
    "moss", "Just the same plain moss you always find on old stones",
    "tomb stone", 
      "It has fallen face down on the grave. Death is often anonymous..",
  });
  property = "Yurei";
  ::reset( arg );
  replace_program( GEN_GRAVE );
}
