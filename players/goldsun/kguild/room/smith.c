
object ob;
inherit "room/room";
#include "../guild.h"


void reset (int flag)
{
if (!ob)
ob=clone_object("/players/tatsuo/guild/npc/sutaki.c");
move_object(ob, PPATH +"smith.c");
     if (flag == 0);
{
set_light(1);
short_desc="A Forge";
     long_desc= BS(
	"     Smoke and steam fill the air here.  In the center of "+
	"the room is a bed of red hot coals casting a hellish crimson glow "+
	"over the walls.  A toolrack is hanging on the east wall and a "+
	"pile of scrap metal lies in the corner.  A shirtless man "+
	"works over the forge evidently crafting a fine sword.\n");

property=({"has_fire"});

items = ({"pit","It is where the Reginus heats his metal"
        });
smell="not ready";

dest_dir = ("/players/goldsun/guild/room/staircase","north"
           });
}
}
