#define PPATH "/players/tatsuo/guild/"
#define TP this_player()
#define TPN TP->query_name()
object ob;
inherit "room/room";
#include "/players/whisky/genesis/sys/break_string.h"


void reset (int flag)
{
if (!ob)
ob=clone_object("/players/tatsuo/guild/npc/sutaki.c");
move_object(ob, PPATH +"smith.c");
     if (flag == 0);
{
set_light(1);
short_desc="A Forge";
     long_desc= break_string(
	"     Smoke and steam fill the air here.  In the center of "+
	"the room is a bed of red hot coals casting a hellish crimson glow "+
	"over the walls.  A toolrack is hanging on the east wall and a "+
	"pile of scrap metal lies in the corner.  A shirtless man "+
	"works over the forge evidently crafting a fine sword.\n",65);

items = ({"entrance", long_desc,
          "archway", "The archway is made from an unfamiliar wood.\n",
          "gateway", "It is raised, you don't think you can figure it out.\n",
          "floor", "It is a polished hardwood floor",
        });
smell = "The sweet smell of the garden finds its way in here.";


dest_dir = ({PPATH +"weap_shop.c","north",
	     PPATH +"armour_shop.c","west",
           });
/* "/players/exos/mountain/garden?","south" */
}
}
