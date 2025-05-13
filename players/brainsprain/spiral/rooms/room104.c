inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset( int arg){
    if(arg)
        return;
  short_desc = "A dark room";
  long_desc =
"As you enter the darkened room, you trip on an unseen object.  Rat droppings "+
"cover the floor.  The walls are made mainly of granite, however there "+
"are several large sections of quartz on the southeastern wall.  The "+
"flutter of wings is barely audible.\n";
  set_light(0);
dest_dir = ({
    sr+"/room103","northeast",
    sr+"/room105","southwest",
  });
  items = ({
    "object",
    "A large chunk of quartz",
  });
    ::reset(arg);
    replace_program("room/room");
}

