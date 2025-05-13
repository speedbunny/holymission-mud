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
			set_name("wyng kong");
			set_alias("kong");
			set_alt_name("wyng");
			set_long("This is a member of the Wyng Kong gang. He "+
			"wears an all black outfit with a red sash. His gang "+
			"is responsible for most of the criminal activity in "+
			"the area. \n");
			set_str(25);
			set_con(23);
			if (query_level()<15){
				set_wc(8 + query_level());
				set_ac(query_level()/2); }
			if(query_level()>14){
				set_wc(20 + query_level()/2);
				set_ac(4 + query_level()/4); }
			GP(800 + query_level(50));
			set_al(-300);
	set_dead_ob(TO());
	}
monster_died(ob){
	MO(CO(YY+"/obj/tag3"), TP());
	return 0; }
