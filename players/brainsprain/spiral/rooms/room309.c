inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A dark hall";
  long_desc =
"You have entered a large wooden paneled room where everything seems to "+
"been paneled with a single piece of wood.  Sections of the wall are "+
"covered with fine etchings.  The room smells faintly of pine.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room308","northeast",
    sr+"/room310","southwest",
  });
  items = ({
    "etchings",
    "Finely etched carvings of woodland animals",
    "wood",
    "A single piece of wood enclosing the whole room",
      });
  ::reset(arg);
    replace_program("room/room");
}
