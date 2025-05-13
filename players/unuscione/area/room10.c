inherit "room/room";
#include "/players/unuscione/def.h"
#include "/players/unuscione/break_string.h"
object umb, bones;

reset(arg){
 if(arg) return;
set_light(0);
short_desc="Lair of the Umber Hulk";
long_desc=break_string(
	"This place reeks of decay.  Scattered about the room "+
	"are many bones of various races.  The walls are  "+
	"gorged with terrible looking claw marks.  This appears "+
	"to be the lair of a particularly violent creature.\n",65);
items=({"place",long_desc,
	"room",long_desc,
	"bones","There are many bones of unlucky travellers.\n"+
	        "You hope you aren't next",
	 "walls","They are gorged with great claw marks",
	  "marks", "Looks like the work of a good solid monster",
	  "claw marks", "Looks like the work of a good solid monster",
	  "lair",long_desc,
	  "creature","It's not here",
	});
smell="ACK it reeks in here";
dest_dir=({KPATH+"room9","south",});
property=({"no_teleport"});
if(!umb || !living(umb)){
MO(CO(MON+"umber"),TO);
}
}
