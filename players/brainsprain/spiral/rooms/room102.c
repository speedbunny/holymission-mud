inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
reset(arg) {

  short_desc = "A cave";
  long_desc =
    "The walls are made of intricately intertwined limestone and granite. "+
    "Water drips from the stalagtites that line the roof of this dank "+
    "cavern.  Dust rises up in clouds as you disturb the inch thick layer on "+
    "the floor.\n";
  set_light(1);
  dest_dir = ({
    sr+"/room101","east",
    sr+"/room103","west",
  });
  items = ({
    "dust",
    "Dust is layered on the floor",
    "floor",
    "The floor of the cavern",
    "water",
    "crystal clear water",
    "roof",
    "The ceiling of the cavern",
    "cavern",
    "The cavern you are presently standing in",
    "walls",
    "They are made of limestone and granite",
    "limestone",
    "It is intertwined with granite to make the wall",
    "granite",
    "It is intertwined with limestone to make the wall",
    "cave",
    "The cave rumored to house the downward spiral",
    "stalagtites",
    "Sharp stalagtites formed from many years of calcification",
  });
    ::reset(arg);
    replace_program("room/room");
}
