inherit "/obj/std_scroll";

#include "/players/tamina/defs.h"

void reset(int arg)
{
  ::reset(arg);
  if (arg) return 0;

  add_name("bark");
  set_long("This is a rough piece of bark, that has fallen\n"+
     	   "from the trunk of a Huorn.  It looks very peculiar,\n"+
	   "in that there is a piece of scribbling on it...\n"+
	   "Perhaps it is magical...\n");
  set_level(1);
  set_value(1500);
  set_read_msg(
    "You read the scribbling on the piece of bark.\n"+
    "You can feel your skin become more tougher, and more protective...\n");
  set_shadow("/obj/shadows/stoneskin_shad", 500 + random(151));

}
