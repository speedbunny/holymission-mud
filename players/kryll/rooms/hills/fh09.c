inherit "/room/room";

#include "/players/kryll/rooms/room_defs.h"
#include "/players/kryll/include/hill_enc.h"

void reset(int arg) {
  rnd_enc_hill();

  clone_list=({
    1, no_of_mons, id_of_mons, file_of_mons, 0,
  });

  ::reset(arg);
  if(arg) return;

  short_desc="End of the path";
  long_desc=
    "The natural path appears to end at some rocks, but at "+
    "closer inspection they look as if they were placed to form "+
    "some primitive stairs.\n";

  set_light(1);

  items=({
    "mountain", "The mountain to the north is the tallest mountain " +
               "around and the peak is obscured by the clouds",
    "clouds", "Large fluffy things floating in the sky",
    "foothills", "Rough, rocky hills",
    "rocks", "They block all the other exits",
    "path", "It is natural and not cut",
    "stairs", "Made of rock but climbable",
  });

  smell="\nThere is a bad taste in the air.\n\n";

  dest_dir=({
    HILLS + "fh08", "south",
    HILLS + "fh15", "up",
  });
}

