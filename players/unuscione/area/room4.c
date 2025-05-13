inherit "room/room";
#include "/players/unuscione/def.h"
#include "/players/unuscione/break_string.h"

reset(arg){
 if (arg) return;
 set_light(0);
 short_desc="Dungeon of Hilo";
 long_desc=break_string(
	"You are in a dark and musty corridor.  The corridor has been "+
	"hewn from the natural bedrock.  Many small footprints lead off "+
	"in all directions.\n",65);
items=({"corridor",long_desc,
	"bedrock","Lithographic Limestone",
	"footprints","Most of them seem to go south",
	});
dest_dir=({KPATH+"room3","north",
	   KPATH+"room7","south",
	});
smell="It smells like wet dog down here";
}
