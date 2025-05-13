inherit "obj/monster";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("leviathan");
	set_short("Leviathan");
	set_long("This is the fabled leviathan. It is a huge, whale-like "+
	"fish. It could swallow you whole without a problem. It looks "+
	"like it's hungry! \n");
	set_level(50);
	set_ac(120);
	set_hp(10000);
	set_number_of_arms(2);
	set_race("leviathan");
	set_wc(30);
	set_size(5);
	}
