inherit "room/room";
#include "/players/trout/defs.h"
int i;

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc= "Rice Fields";
	long_desc= "You are standing in the middle of a rice patty field. "+
	"Several sections of water are cased in by thin, clay dams. This is "+
	"where the city of Mikawa get thier staple crop. Many peasants are "+
	"responsible for the life of this field, for it is the life of this "+
	"city. A path runs through here from west to east. \n";
	DD= ({ ZZ+"/rice2", "west",
		ZZ+"/rice4", "east" });
	items= ({ "dams" "Very small dams, only about 3 feet high, hold the "+
		"water in" });
	for(i=0; i<RAN(5); i++)
		{MO(CO(MM+"/peasant"), TO()); }
	::reset(arg);
	replace_program("room/room");
	}
