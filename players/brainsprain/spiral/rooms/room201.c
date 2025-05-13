inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset( int arg){
  short_desc = "A stairway connecting the first and second levels";
  long_desc =
"Water rushes down from above.  The ground is covered in a foot of water.  "+
"The water flows to the northern corner of the room where it drains into "+
"a cistern at the end of the room.  The walls are caked with dried mud.\n";
  set_light(1);
  dest_dir = ({
    sr+"/room120","up",
    sr+"/room202","northwest",
  });
  items = ({
    "mud",
    "A mix of the dust from the floor and the water has sprayed against the wall",
    "ground",
    "Many years of erosion have caused this ground to be smooth and the water\n"+
    "continues to rush over it creating an underground stream",
    "water",
    "A thick, brown water that smells like sewage",
    "cistern",
    "A huge hole at the southern end of the room.",
  });
  ::reset(arg);
  replace_program("room/room");
}
