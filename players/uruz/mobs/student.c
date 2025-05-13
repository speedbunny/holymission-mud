inherit "obj/monster";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("student");
	set_short("Hwrang-do Student");
	set_long("This is a student of the Hwrang-Do Karate school. He wears "+
	"a standard karate gi, with a colored silk sash in place of the belt."+
	" He looks ready to defend himself \n");
	set_level(5 + RAN(6));
	set_al(-100 + RAN(200));
	set_hp(query_level() * 25);
	set_race("human");
	set_wc(query_level() + 3);
	set_ac(query_level()/3);
	set_size(3);
	add_money(query_level() * 55);
	set_number_of_arms(2);
	set_gender(1);
	}
