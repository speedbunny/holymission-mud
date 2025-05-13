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
	set_level(10 + RAN(6));
	set_al(-100 + RAN(200));
	set_race("human");
	set_ac(1+ query_level()/2);
	set_size(3);
	add_money(query_level() * 30);
	set_number_of_arms(2);
	set_gender(1);
	switch(query_level())
	{	case 10..11: MO(CO(WW+"/jo"), TO());
			     set_hp(250);
			     set_wc(5);
			     break;
		case 12..13: MO(CO(WW+"/spear"), TO());
			     set_hp(360);
			     set_wc(5);
		 	 break;
		case 14: MO(CO(WW+"/sword"), TO());
			 set_hp(490);
			 set_wc(8);
			 break;
		case 15: MO(CO(WW+"/knives"), TO());
			 set_hp(600);
			 set_wc(9);
			 break;
	}
	IC("powerup");
	}
