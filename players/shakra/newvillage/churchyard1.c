/*
 * Author : Uglymouth
 * Date   : 9-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc = "The churchyard";
  long_desc = "You stand between ancient tombes on the village churchyard.\n"
        + "This place is entirely enclosed by walls and hedges. A small gravel\n"
        + "path leads between the tombes. Although the churchyard lies directly\n"
        + "south from the busy village square it's dead silent here. You feel\n"
        + "this might not be a good place to be at night.\n";
  dest_dir = ({ PATH+"church1","west" });
  items = ({ "tombes","Those are the tombes of the priests that once served this church",
        "churchyard","A place to burry the dead. There are not many places left",
        "walls","A wooden wall rises east and the church wall west",
        "hedges","North and south of the churchyard grow thick thornhedges",
        "path","A narrow gravel path. Moss growing on it indicates it's not used very often",
        "square","You can't see it through the hedge",
        });

  replace_program("room/room");
  }

