inherit "/room/room";

#include <room_defs.h>

string look_at_wall() {
  int diff, tmp;

  tmp = TP->query_wis()+TP->query_int()+random(30);
  diff = tmp - random(100);

  if(diff <= 0) {
    return "The town wall stands a good 10 feet tall, protecting "+
           "the inhabitants from the dangers that lurk outside. "+
           "It is a marvel of engineering, considering the time "+
           "at which it was built";
  }
  switch(diff) {
    case 1..10 :
    case 11..20 :
    case 21..40 :
    case 41..80 :
    default :
  }
  return "You look at the wall";
}

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc = "The end of Main Street";
  long_desc =
    "Main street continues north here. The town wall blocks any "+
    "travel south and the back of a building blocks travel to the "+
    "west. To the east is the entrance to Chantilly's beautiful "+
    "garden.\n";

  dest_dir = ({
    HM_VILLAGE + "street17", "north",
    VILLAGE_GARDEN + "entrance", "east",
  });

  items = ({
    "main street", "The major road through the village",
    "street", "The major road through the village",
    "buildings", "You see no visible entrances into the buildings",
    "entrance", "There are none",
    "wall", "@@look_at_wall@@",
  });

  ::reset(arg);
}

