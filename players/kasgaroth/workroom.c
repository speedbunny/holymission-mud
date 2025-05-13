
#include "defs.h"
#include "private/ansi.h"

inherit "room/room";

int locked;

void reset(int arg)
{
    ::reset(arg);
    if (arg)
	return;
    set_light(1);
    short_desc = GREEN + "Kasgaroth's Green Space" + NORMAL;
    long_desc = GREEN + "Kasgaroth's Green Space" + NORMAL + ".\n";
    dest_dir = ({
      GARDEN + "entrance","garden",
      "/players/kryll/guild/room","guild",
      "room/church","church"
    });
}

void init()
{
    ::init();
    if (locked)
    {
	this_player()->move_player("because Kasgaroth is busy#room/church");
	tell_object(this_player(),"Kasgaroth isn't seeing anyone.  Try later.\n");
    }
    //    if (this_player()->query_real_name() == "kasgaroth")
    //	add_action("lockit","lockit");
}

int lockit(int level)
{
    if (level)
	locked = level;
    tell_room(this_object(),"This room locked at level "+locked+".\n");
    return 1;
}
