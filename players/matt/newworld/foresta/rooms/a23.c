inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(-1);
  short_desc = "Deep Forest";
  long_desc =
    "    You sense that you are near a strong evil force. The deep\n" +
    "darkness around you seems to move hungrily in slow circles\n" +
    "through the wasted trees and seep into your soul, chilling you\n" +
    "from the inside. The eyes of watchers hidden in the shadows\n" +
    "follow your every move with their baleful gaze, as if waiting\n" +
    "for you to make a wrong move.\n" +
    "    The fear instilled by this place is almost overwhelming.\n" +
    "It seems to get darker to the west.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a24", "west",
    NWFORESTA + "rooms/a21", "east",
  });

  items = ({
    "darkness", "A blackness so thick you can almost feel it",
    "trees", "Old, withered pieces of what might once have been trees",
    "watchers", "It is too dark to see them clearly",
    "shadows", "You sense movement and sinister life within the shadows",
    "eyes", "Tiny unblinking orbs that watch you",
  });
  replace_program("/room/room");
}
