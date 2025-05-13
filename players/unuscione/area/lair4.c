inherit "room/room";
#include "/players/unuscione/def.h"
void reset(int arg){
 if(arg) return;
 ::reset(arg);

set_light(0);
short_desc="In the lair of the kobold";
long_desc="     The smell of dog reaches a stifling apex here in what "+
	"appears to be the lair of the kobolds.  Bones and furs are scattered "+
	"about the cavern in total disregard for any assemblence of order.  "+
	"Crude tools and furniture lie about in various states of repair.  "+
	"The cavern heads off in several directions enter smaller chambers.\n";
dest_dir=({KPATH+"lair5","east",
	   KPATH+"lair6","west",
	   KPATH+"lair7","north",
	   KPATH+"lair1","south"});
smell="It smells like wet dog.";
items=({"lair","A small cavern tunneled out by the kobolds",
	"tools","Umm, you have seen better",
	"furniture","If thats what you want to call it",
	"chambers","They may warrant closer investigation"});
replace_program("/room/room");
}
