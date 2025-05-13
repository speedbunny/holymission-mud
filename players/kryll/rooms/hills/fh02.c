inherit "room/room";

#include "/players/kryll/rooms/room_defs.h"
#include "/players/kryll/include/hill_enc.h"

void reset(int arg) {
  rnd_enc_hill();

  clone_list=({
    1, no_of_mons, id_of_mons, file_of_mons, 0,
  });

  ::reset(arg);
  if(arg) return;

  short_desc="Foothills Path";

  long_desc=
    "This natural path winds its way through the rocks to "+
    "the mountain. You sense evil all around you.\n";

  set_light(1);

  items=({
    "mountain","The mountain to the north is the tallest mountain\n" +
               "around and the peak is obscured by the clouds",
    "clouds","Large fluffy things floating in the sky",
    "foothills","Rough, rocky hills",
    "rocks","They block all the other exits",
    "path","It is natural and not cut",
  });

  smell="\nThere is a taint of evil in the air.\n\n";

  dest_dir=({
    HILLS + "fh01", "south",
    HILLS + "fh03", "north"
  });
}
