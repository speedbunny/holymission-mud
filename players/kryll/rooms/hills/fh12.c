inherit "/room/room";

#include "/players/kryll/rooms/room_defs.h"

void reset(int arg) {
  short_desc="A path opening";
  long_desc= 
    "This opening among the rocks appears to be an unnatural "+
    "creation used for ambushes. The path continues to the "+
    "mountain to the north.\n";

  set_light(1);

  items=({
    "mountain", "The mountain to the north is the tallest mountain " +
              "around and its peak is obscured by the clouds",
    "clouds", "Large fluffy things floating in the sky",
    "opening", "Looks to be cut out",
    "foothills", "Rough, rocky hills",
    "rocks", "Lots of large boulders",
    "path", "It is natural and not cut",
   });

  smell="\nThere is a fresh aroma of flowers, as though trying to "+
    "mask an odor.\n\n";

  dest_dir=({
    HILLS + "fh14", "north",
    HILLS + "fh13", "east",
    HILLS + "fh10", "south",
  });

  ::reset(arg);
  replace_program("room/room");
}

