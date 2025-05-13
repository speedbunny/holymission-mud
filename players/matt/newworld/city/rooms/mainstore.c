#include "/players/matt/defs.h"

inherit ROOM + "store";

object muffs, prism, watch, cross, torch;

reset(arg) {
  ::reset(arg);
  long_desc = "Everything from the Main Shop is stored here.\n";
  if(arg) return;
}
     
inventory(arg) {
  standard();
  ::inventory(arg);
}

buy(arg) {
  standard();
  ::buy(arg);
}

standard() {
  if(!present("earmuffs", TO)) {
    muffs = clone_object(NWCITY + "objects/muffs");
    MOVE(muffs, TO);
  }
  if(!present("empty prism", TO)) {
    prism = clone_object(NWCITY + "objects/glassprism");
    MOVE(prism, TO);
  }
  if(!present("small watch", TO)) {
    watch = clone_object(NWCITY + "objects/watch");
    MOVE(watch, TO);
  }
  if(!present("magic crossbow", TO)) {
    cross = clone_object(NWCITY + "objects/anti_air");
    MOVE(cross, TO);
  }
  if(!present("torch", TO)) {
    torch = clone_object("/obj/torch");
    MOVE(torch, TO);
  }
}
