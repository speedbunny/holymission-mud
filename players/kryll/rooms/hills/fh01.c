inherit "room/room";

#include "/players/kryll/rooms/room_defs.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  short_desc="Foothill Path";

  long_desc=
    "You have entered the foothills surrounding the North "+
    "Mountains. The landscape looks very rocky "+
    "and many huge rocks block your way by any other means "+
    "except by the natural rudimentary path. You notice something "+
    "is carved upon the east rock.\n";

  set_light(1);

  items=({
    "east rock","You make out some carvings. Perhaps you should read them",
    "mountain","The mountain to the north is the tallest mountain\n"+
               "around and its peak is obscured by the clouds",
    "mountains","These are the foothills of the mountains to the north",
    "clouds","Large fluffy things floating in the sky",
    "lanscape","Surely you mean the foothills",
    "foothills","Rough, rocky hills",
    "rock","The east rock has carvings on it",
    "path","A natural pass through the hills",
    "rocks","They block all the other exits",
    "carvings","These carvings are in a language you can understand.\n"+
               "Perhaps you should read them",
  });

  smell="\nThere is a taint of evil in the air.\n\n";

  dest_dir=({
    HILLS + "fh02", "north",
    PATH + "ep24", "south",
  });
}

void init() {
  ::init();
  add_action("_read","read");
}

status _read(string str) {
  switch(str) {
    case "east rock" :
    case "rock" :
    case "carvings" :
      writelw("\n\nBEWARE! There are kobolds here!\n");
      writelw("They may attack on sight....\n\n");
      return 1;
    default :
      notify_fail("Read what?\n");
      return 0;
  }
}
