inherit "room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "The churchyard";
  long_desc =
    "You stand between ancient tombes on the village churchyard. "+
    "This place is entirely enclosed by walls and hedges. A small "+
    "gravel path leads between the tombes. Although the churchyard "+
    "lies directly south from the busy village square, it is deadly "+
    "silent here. You feel this might not be a good place to be "+
    "at night.\n";

  dest_dir = ({
    HM_VILLAGE + "church1", "west"
  });

  items = ({
    "tombes","Those are the tombes of the priests that once served "+
      "this church",
    "churchyard","A place to burry the dead. There are not many places left",
    "walls","A wooden wall rises east and the church wall west",
    "hedges","North and south of the churchyard grow thick thornhedges",
    "path","A narrow gravel path. Moss growing on it indicates it's "+
      "not used very often",
    "square","You can't see it through the hedge",
  });

  ::reset(arg);
  replace_program("room/room");
}

