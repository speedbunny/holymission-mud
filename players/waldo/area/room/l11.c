#include "/players/waldo/defs.h"

inherit "room/room";

reset (arg)
{
  if (!arg)
  {
    set_light(1);
    short_desc="Outside a cave.";
    long_desc=
	"You stand before the entrance of a huge cave. A faint\n"+
	"glow seems to permeate from the walls. You sense an\n"+
	"eerie feeling about the place.\n";

    dest_dir=({
	MYAREA+"/room/l12","south",
	/*Insert exit to connection here*/
       "/players/warlord/hill1","east",
      });
    }
  }

init()
{
  ::init();
  }
