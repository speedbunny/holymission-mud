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
dest_dir=({KPATH+"lair2","east",KPATH+"lair3","west",KPATH+"lair4","north",
	   KPATH+"room13","south"});
smell="It smells like wet dog.";
items=({"lair","A small cavern tunneled out by the kobolds",
	"tools","Umm, you have seen better",
	"furniture","If thats what you want to call it",
	"chambers","They may warrant closer investigation"});
replace_program("/room/room");
}
