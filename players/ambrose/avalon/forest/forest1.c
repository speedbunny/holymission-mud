#include "/players/ambrose/room.h"
#include "/players/ambrose/defs.h"

void reset(int arg)
 {
  ::reset(arg);
    if(arg)
       return;
      set_light(1);
      short_desc="The entrance to the forest";
      long_desc=
      "You have reached the forest entrance, around you can hear the sounds \n"
     +"of life.  This forest seem to be made up pines and spruces, the scent \n"
     +"of them fills the air around.  You seem to be able to go anywhere from\n"
     +"here except to the west where the mountains block your progress.  \n"
     +"There is a path that leads up from here into the mountains that you\n"
     +"you could try.\n";
      property=({"no_teleport"});
      dest_dir=({
                AVAL +"entrance/cliff3","up",
                AVAL +"forest/forest2","east",
                AVAL +"forest/forest3","northeast",
                AVAL +"forest/forest4","southeast",
      });
      items=({
      "forest","Green and lush this forest exudes life.",
      "spruce","Green spruce trees rise to the forest ceiling.",
      "pine","Pine trees stand here leaving needles on the forest floor.",

           });
       smell="Doesn't smell like anything.";
     }
