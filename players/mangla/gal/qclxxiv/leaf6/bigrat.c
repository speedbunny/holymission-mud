#include "/players/qclxxiv/mymonster.h"
object fur, claws;
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("big rat");
	set_alias("rat");
	set_race("skum");
	set_level(10);
   	set_wc(10);
	set_ac(3);
   	set_hp(322);
	set_sp(100);
	set_al(-4);
   	set_aggressive(0);
   	set_short("A big rat");
   	set_long("A big grubby rat, coming straight from the sewer.\n");
	set_size(3);
	PLACE_IN_THIS(fur,HOME+"leaf6/bigratfur");
	init_command("wear fur");
	PLACE_IN_THIS(claws,HOME+"leaf6/bigratclaws");
	init_command("wield claws");
}

