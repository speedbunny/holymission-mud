inherit "obj/monster";
#include "/players/trout/defs.h"

reset(arg){

	::reset(arg);
	if (arg) return;
	set_alias("fish");
	switch( RAN(5)){

	case 0: set_name("beta");
		set_short("Beta");
		
		set_level(10);
		set_al(50);
		set_hp(200);
		set_long("It is a beta, the japanese fighting fish. \n");
		set_wc(8);
		set_ac(3);
		break;
	
	case 1:
		set_name("carp");
		set_short("Carp");
		set_level(5);
		set_hp(30);
		set_ep(300);
		set_long("A big nasty carp. \n");
		set_wc(3);
		break;
	case 2:
	
		set_name("flounder");
		set_short("Flounder");
		set_level(5);
		set_hp(90);
		set_long("A great big flounder. \n");
		set_wc(4);
		set_ac(1);
		break;
	case 3:
		set_name("tuna");
		set_short("Tuna");
		set_level(3);
		set_hp(50);
		set_long("The tuna looks tasty. \n");
		set_wc(2);
		break;
	case 4:
		set_name("rainbow trout");
		set_short("rainbow trout");
		set_level(7);
		set_hp(5000);
		set_long("You know that if this fish were to be harmed, the "+
		"fish-god 'Trout' would be very angry!");
		set_wc(8);
		set_ac(6);
		break;
		}

	}
