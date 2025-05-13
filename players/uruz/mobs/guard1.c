inherit "players/trout/mobs/guard_help";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("temple guard");
	set_long("This is one of the guards of Hono Ji. He is a well trained"+
	" warrior, and would fight to the death for his daimyo. This "+
	"samurai looks pretty well equipped. \n");
	set_alias("guard");
	set_al(200);
	set_level(16);
	set_hp(800);
	set_gender(1);
	GP(1200);
	set_ac(4);
	set_wc(22);
	set_number_of_arms(2);
	MO(CO(AAA+"/hanburi"), TO());
	MO(CO(AAA+"/hara_ate"), TO());
	MO(CO(AAA+"/sune_ate"), TO());
	IC("powerup");
	set_dead_ob(TO());
	}
init(){
	::init();
	if(present("tag1", TP())){
		write("Guard says: No one steals from Lord Tokugawa! Die "+
		"thief! \n");
		set_aggressive(1); }
	}
monster_died(ob){
		MO(CO(WW+"/katana"), TO());
		return 0;
		}
