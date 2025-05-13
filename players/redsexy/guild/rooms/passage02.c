inherit "/room/room";

#include "/players/redsexy/guild/guilddefs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Dark Passage";
  long_desc =
    "    You stand in a dark, rough passage leading into the heart of\n" +
    "the mountain to the north and back outside to the southwest. The\n" +
    "dust of centuries slowly and silently covers the rocky ground in\n" +
    "a dull layer; the only sounds here are the eery echoes of your\n" +
    "own movements.\n";

  dest_dir = ({
    "players/redsexy/guild/rooms/passage03", "north",
    "players/redsexy/guild/rooms/passage01", "southwest",
  });

  items = ({
    "passage", "A very old passage cut into the mountain",
    "mountain", "From the inside, the mountain is cool and dark",
    "dust", "A rather thick layer of dust, only slightly disturbed",
    "ground", "The ground here is rough and rocky",
  });
  replace_program("/room/room");
}
