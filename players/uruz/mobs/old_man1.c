inherit "obj/monster";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("old man");
	set_alias("man");
	set_short("Old Man");
	set_long("This is the old man that someone pushed off the bridge "+
	"up above. He looks as if he is about to drown! Maybe you should try "+
	"to save him? \n");
	set_al(40);
	set_level(9);
	set_hp(130);
	set_ac(3);
	set_wc(8);
	set_race("human");
	set_gender(1);
	set_size(2);
	add_money(200);
	}
init(){
	::init();
	AA("_save", "save");
	}
_save(str){
	if(!str){
		notify_fail("Save whom? \n");
		return 0; }
	if(str=="old man" || str=="man")
		{write("You grab a hold of the old man and drag him ashore"+
			". \n");
		say(TPN+" drags the old man ashore, saving his life! \n", 
			TP());
		TP()->add_alignment(150);
		TP()->move_player("up#players/trout/area/fief4");
		write("The old man says: Thank you! I wouldn't want to "+
		"stay down there with that leviathan in the area. I hear "+
		"he's attracted by bloody fish. Maybe you can 'bait' him "+
		"with one?\n");
		MO(CO(MM+"/old_man"), ZZ+"/fief4");
		destruct(TO());
		return 1;
		}
	}
