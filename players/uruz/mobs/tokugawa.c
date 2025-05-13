inherit "/players/trout/mobs/guard_help";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("Tokugawa Ieyasu");
	set_alias("tokugawa");
	set_long("This is the famous Tokugawa Ieyasu, Daimyo of the fief Mikawa"+
	". He stands only five feet, eight inches tall, and looks like he is in"+
	" his 50's. It is "+
	"hard to believe that this man became a king through his own will. He "+
	"is a seasoned veteran. It would be wise not to anger him! \n");
	set_al(50);
	set_level(35);
	set_hp(5700);
	set_race("human");
	set_gender(1);
	GP(5000);
	set_number_of_arms(2);
	set_dead_ob(TO());
	set_ac(25);
	set_wc(60);
	MO(CO(AAA+"/sode"), TO());
	MO(CO(AAA+"/sune_ate"), TO());
	MO(CO(AAA+"/kabuto"), TO());
	MO(CO(AAA+"/kote"), TO());
	MO(CO(AAA+"/o_yoroi"), TO());
	IC("powerup");
	}
monster_died(ob){
		MO(CO(WW+"/katana1"), TO());
		MO(CO(WW+"/wakazashi"), TO());
		return 0;
		}
