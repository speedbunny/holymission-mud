inherit "/room/room";

#include "/players/brainsprain/guild/headers.h"
void reset(int arg)
{
    ::reset(arg);
    if (arg)
	return;
    set_light(1);
    short_desc = "Fence Store-room";
    long_desc = "The Fence's storage room.\n";
    dest_dir = ({
      ROOMDIR+"fence","up"
    });
}
