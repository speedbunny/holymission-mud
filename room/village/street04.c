inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "At the crossroads";

  long_desc =
    "You stand at a crossing. Main Street continues east and "+
    "west. To the north lies Rich Men's Road. To the south you can "+
    "enter an obscure little alley.\n";

  dest_dir = ({
    HM_VILLAGE + "road1", "north",
    HM_VILLAGE + "street03", "east",
    HM_VILLAGE + "square1", "west", 
    HM_VILLAGE + "alley1", "south",
  });

  items = ({
    "crossing","Here Main Street crosses Rich Men's Road and "+
      "some obscure alley",
    "main street","The major road through the village",
    "rich men's road","This road owns its name to the kind of "+
      "people living on it",
    "road""This road owns its name to the kind of "+
      "people living on it",
    "alley","Such an alley as where you'd expect either some "+
      "mysterious little shop, or more likely, the local gang of thugs",
  });

  ::reset(arg);
  replace_program("room/room");
}

