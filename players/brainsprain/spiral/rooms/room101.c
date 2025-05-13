inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
  short_desc = "The entrance to a cave";
  long_desc =
    "A huge maw opens up before you.  It seems as if the very ground "+
    "threatens to swallow you whole.  The smell of death and decay comes "+
    "out of the cave and no plants grow here.  Only a little bit of light "+
    "filters in from the outside world.  A sign has been driven into the "+
    "ground here.\n";
  set_light(1);
  dest_dir = ({
    sr+"/isla9","out",
    sr+"/room102","west"
  });
  items = ({
    "cave",
    "A gaping maw of an entrance",
    "sign",
    "Abandon all hope ye who enter here... The Realm of Darkstaff",
    "maw",
    "The opening to a cave.... It is very dark inside",
    "ground",
    "The ground seems to tremble as you walk on it",
  });
    clone_list = ({ 1, 2, "rat", sm+"/rat.c", 0 });
    ::reset(arg);
    replace_program("room/room");
}
