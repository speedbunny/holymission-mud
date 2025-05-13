inherit "obj/monster";
#include "/players/trout/defs.h"

reset(tick){
	::reset(tick);
	if(tick) return;
	set_number_of_arms(2);
	set_race("human");
	set_gender(1);
	set_size(3);
	set_level(12 + RAN(9));
			set_name("fighting tong");
			set_alias("tong");
			set_long("This is a member of the Fighting Tong gang."+
			" He wears a white gi, with a gold headband. He "+
			"fights for the cause of good. \n");
			set_dex(25);
			set_str(21);
			set_wc(query_level() * 1.5);
			set_ac(3 + query_level()/2);
			set_al(325);
			GP(300 + RAN(500));
			set_al(-300);
	set_dead_ob(TO());
	}
monster_died(ob){
	MO(CO(YY+"/obj/tag2"), TP());
	return 0; }
