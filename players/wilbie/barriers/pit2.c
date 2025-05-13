inherit "/room/room";
#include "/players/wilbie/def.h"
  reset(arg){
  if(!arg){

  set_light(0);
  short_desc="A deep pit";

  long_desc=
  "You find yourself on an outcropping of cold granite.  Hanging from the "+
 "ledge is the charred corpse of a human, his armor melted to uselessness "+
  "by what had to be unnaturally hot flame.  Below, you smell ancient "+
  "odors of death, and the occasional scream can be heard.\n";
  items=({
  "outcropping","It is a ledge that saved you from a long fall",
  "ledge","It is carved from the granite wall",
  "wall","It is pure granite, like the cathedral walls",
  "granite","This could be where they got the granite to build the "+ 
            "cathedral.  Whoever 'they' are",
  "corpse","It is charred beyond all recognition",
  "armor","It is melted completely",
  "human","The burnt remains of a human, charred beyond recognition",
  });
  smell="It is a mixture of rotting flesh and brimstone.";

  dest_dir=({
  GPATH+"hell1","down",
  GPATH+"pit1","up",
  });

  }
::reset(arg); replace_program("/room/room");
  }
