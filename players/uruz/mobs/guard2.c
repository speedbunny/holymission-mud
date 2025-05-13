inherit "players/trout/mobs/guard_help";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("elite guard");
	set_long("This is one of the elite personal guards of Daimyo Tokugawa."+
	" These warriors are the best in the land, and have a fanatical devotion"+
	" to their lord. \n");
	set_alias("guard");
	set_al(350);
	set_level(20);
	set_hp(1800);
	set_race("human");
	set_gender(1);
	GP(2000);
	set_number_of_arms(2);
	set_wc(30);
	set_ac(6);
	MO(CO(AAA+"/kabuto"), TO());
	MO(CO(AAA+"/kote"), TO());
	MO(CO(AAA+"/do_maru"), TO());
	MO(CO(AAA+"/sune_ate"), TO());
	IC("powerup");
	set_dead_ob(TO());
	}
monster_died(ob){
		MO(CO(WW+"/katana"), TO());
		return 0;
		}
hit_player(dam){
	switch(RAN(100)){
			case 0..20:
				  TP()->HIT(50);
				 write("A guard performs a Kiai attack!\n");
				TLR( ENV(), "A guard rushes "+TPN+" and "+
				"strikes with a loud shout! \n");
				  break;
			default: break;
			}
	return:: hit_player(dam);
	}
init(){
	::init();
	if(present("tag1", TP())){
		write("Guard says:No one steals from Lord Tokugawa! Die "+
		"thief! \n");
		set_aggressive(1);
		}
	}
