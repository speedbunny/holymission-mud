inherit "/room/room";

#include "/room/room_defs.h"

status move(string str) {
  if(!str)
    str = query_verb();
  if(str == "east")
    writelw("You leave the village through the gate. "+
            "Clack! The gate closes again behind your back. \n");
  return ::move(str);
}

void reset(int arg) {
  set_light(1);
  short_desc = "Behind the gate";

  long_desc =
    "You stand just behind the gate in the village proper. "
    "A guard house stands north, and the center of the village lies west. "
    "You notice that this village is built around the local church.\n";

  dest_dir = ({
    HM_VILLAGE + "guardhouse", "north",
    HM_VILLAGE + "street01", "east",
    HM_VILLAGE + "street03", "west",
  });

  items = ({
    "gate","A gate in the stockade, leading out of the village",
    "stockade","A wooden stockade extends north and south to protect "+
      "the village", 
    "village","A simple woodsmen's village",
    "house","A wooden house that accomodates the city guard",
    "center","Most buildings are built around the church square",
    "buildings","Mostly wooden buildings",
    "church","A nicely crafted wooden church stands in the center "+
      "of the square",
    "square","A cobblestone square forms the centre of the village",
  });

  ::reset(arg);
  replace_program("room/room");
}

