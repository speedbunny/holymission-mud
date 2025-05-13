#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 1 );
  short_desc = "At the top of the second dark hill in a dark land.";
  long_desc = "You stand at the top of the second dark hill. To the east "
    + "you see nothing but barren lands, where there were once fertile "
    + "fields. You don't see anything of interest in these lands at all. "
    + "Next to you are the ruins of another small farm. This one hasn't "
    + "burned down, but was destroyed by force. It is now covered with "
    + "some kind of black moss. A small path runs from the ruins to the "
    + "west and northwest down the hill.\n";
  dest_dir = ({
    ROOM_DIR + "darkld07", "west",
    ROOM_DIR + "darkld09", "northwest",
  });
  hidden_dir = ({
    ROOM_DIR + "cave01", "down",
  });
  items=({ 
    "top", "From the top you see other hills to the northwest and "
      + "southwest. A cemetery lies far south. Everywhere east from this "
      + "hill are nothing but barren lands. Far north you notice a tower",
    "lands", "Formerly fertile crop yielding fields. Now almost deserts",
    "barren lands", 
      "Formerly fertile crop yielding fields. Now almost deserts",
    "hill", "The second in a chain of low, dark and depressing hills. You "
      + "start wondering if this land is completely deserted..",
    "ruins", "The walls have been broken down and the roof collapsed. In "
      + "between the rubble you notice the remains of some furniture",
    "farm", "The walls have been broken down and the roof collapsed. In "
      + "between the rubble you notice the remains of some furniture",
    "rubble", "Rocks, broken beams, rotten thatch, crushed glass, etc"
    "furniture", "A couple of broken chairs and cupboards",
    "chairs", "Just some old kitchen chairs, which are now just firewood",
    "cupboards", "Some half intact little doors are all that's left",
    "doors", "When you lift one, you notice a hole in the ground",
    "hole", "It is wide enough for you. It leads down into the dark",
    "moss", "Deep black hairy moss that burns your hand if you touch it",
    "path", "A narrow strip of different vegetation gives its route away",
  });
  ::reset( arg );
  replace_program( "room/room" );
}
