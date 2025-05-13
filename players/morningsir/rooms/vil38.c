inherit "/room/room";

#include "/players/morningsir/defs.h"

reset(arg) {
  if(!arg) {

  set_light(1);
  short_desc="Near the village.";
  long_desc=
   "You are standing on a dry road just in front of a village which lies in\n" +
   "north-western direction. The road continues in southeast direction. You\n" +
   "can see vast corn fields in the south-west while a pretty high hill with\n" +
   "dense trees rises on the east.\n";

  dest_dir=({ PATHR + "vil37.c", "northwest",
              PATHR + "vil39.c", "southeast"
             });

  items=({ "village", "The village looks alive.",
           "road", "The road is more a forest path, but it's dry and wide.",
           "hill", "The hill is overgrown with a dense forest which seems unpassable.",
           "fields", "Yes, those fields are definitely corn fields and are rather large."
          });

  smell="You feel various aromas coming from the marketplace.";

  }
  replace_program("room/room");
}
