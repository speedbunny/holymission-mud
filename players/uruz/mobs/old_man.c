inherit "obj/monster";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("old man");
	set_alias("man");
	set_short("Old Man");
	set_long("He is a very old man, with long white hair, and a "+
	"white beard to match. He wears a large sun hat, and plain "+
	"robes. As he smiles, you notice several teeth missing. He "+
	"usually sits too close to the edge of the bridge, "+
	"and gets pushed in because of it! \n");
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
	AA("_push", "push");
	}
_push(str){
	if(!str){
		notify_fail("Push what? \n");
		return 0; }
	if(str=="old man" || str=="man")
		{ write("You push the old man into the Ane River! The "+
		"splash gets you wet in the process. How cruel! \n");
		say(TPN+" pushes the old man into the river. How cruel! \n",
			TP());
		TP()->add_alignment(-150);
		MO(CO(MM+"/old_man1"), ZZ+"/river6");
		destruct(TO());
		 return 1;
		}
	}
