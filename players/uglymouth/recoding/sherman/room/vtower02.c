#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  clone_list = ({
    1, 4, "vampire guard", MON_DIR + "vguard", 0,
  });
  set_light( 1 );
  short_desc = "In the lobby of a black tower.";
  long_desc = "You have come to the lobby of the black tower that was once "
    + "the proud mansion of the lord of these lands. The lobby is a big "
    + "round chamber. The walls are covered with thick tapestries depicting "
    + "tragic scenes. On the floor lies a big woolen rug. Two torches "
    + "illuminate the lobby dimly. A wide, spiralling flight of stairs "
    + "leads both up and down.\n";
  dest_dir = ({
    ROOM_DIR + "vtower01", "out",
    ROOM_DIR + "vtower03", "up",
    ROOM_DIR + "vtower07", "down",
  });
  items=({
    "lobby", "It's a luxurous place, but not a joyous one",
    "chamber", "It's a luxurous place, but not a joyous one",
    "tower", "You're inside it. If you want to see it, go outside..",
    "tapestries", "They are richly woven, but all depict graveyards",
    "rug", "It's woven of black wool, with in its centre a red skull "
      + "with prolonged corner teeth",
    "torches", "Normal torches, burnt up for about two-thirds",
    "flight", "You could easily walk it two persons side by side",
  });
  property = ({ "has_fire" });
  ::reset( arg );
  replace_program( "room/room" );
}
