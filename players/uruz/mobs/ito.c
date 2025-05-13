inherit "obj/monster";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("Ito Hyuga");
	set_alias("ito");
	set_alt_name("hyuga");
	set_long("This is General Ito Hyuga, first general of Tokugawa Ieyasu's"+
	" army, and his finest warrior. He is a middle aged man, with a hardened"+
	" look. He is a master with a sword, and is a skilled tactician.\n");
	set_al(250);
	set_level(28);
	set_hp(3600);
	set_race("human");
	set_gender(1);
	set_number_of_arms(2);
	set_wc(50);
	set_ac(13);
	GP(10000);
	MO(CO(AAA+"/o_yoroi"), TO());
	MO(CO(AAA+"/kabuto"), TO());
	MO(CO(AAA+"/sode"), TO());
	MO(CO(AAA+"/sune_ate"), TO());
	MO(CO(AAA+"/w_boots"), TO());
	MO(CO(AAA+"/kote"), TO());
	IC("powerup");
	set_dead_ob(TO());
	}
monster_died(ob){
		MO(CO(WW+"/katana1"), TO());
		return 0;
		}
