inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Mountain Road";
  long_desc =
    "    You look about you in sheer wonder at the snow. It covers\n" +
    "the road and everything around it in a thin blanket, and seems\n" +
    "to carry with it the silence of winter. You are very high up\n" +
    "now, and you see the landscape spread out far below you to the\n" +
    "south. The road itself leads southwest and southeast.\n" +
    "    Though your view to the north is obstructed by the face\n" +
    "of the mountain, you notice something protruding into the sky\n" +
    "far above you.\n";

  dest_dir = ({
    NWROAD + "rooms/road19", "southwest",
    NWROAD + "rooms/road17", "southeast",
  });

  items = ({
    "road", "The road here is slippery, covered by a thin layer of snow",
    "snow", "White powdery snow covering the mountain before you",
    "mountain", "Here the mountain is rather steep",
    "something", "It looks like a pinnacle",
    "pinnacle", "The pinnacle of a black tower",
    "landscape", "The view of the land from this height is beatiful",
  });
  replace_program("/room/room");
}
