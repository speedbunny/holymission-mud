

inherit "/players/trout/area/random_peasant";

#include "/players/trout/defs.h"
#define RSP restore_spell_points


reset(arg){
	if(arg) return;
	set_light(1);
	short_desc= "Massage Parlor";
	long_desc= "This is the best massage parlor in town. Many people come "+
	"here to relax after a hard days work. It has a comfortable atmos"+
	"phere, and everyone talks freely here. Massage tables fill the back"+
	" section of the room. A sign hangs on the wall. \n";
	DD= ({ ZZ+"/mroad1", "west" });
	items= ({ "table", "A padded table with a hole to rest your face in",
		"sign", "A large sign. Maybe you should read it?" });
	}
init(){
	::init();
	AA("_read", "read");
	AA("_buy", "buy");
	AA("_buy", "order");
	}
_read(str){
	if(!str){
		notify_fail("Read what?\n");
		return 0;
		}
	if(str=="sign"){
		write("*********************************************\n");
		write("**   Mikawa Massage Parlor		  **\n");
		write("*********************************************\n");
		write("1) Foot Massage  \n");
		write("2) Back Massage \n");
		write("3) Neck Rub \n");
		write("4) Full Body Massage \n");
		write("\n Order by name or number! \n");
		return 1;
		}
	}
_buy(str){
	if(str=="1"||str=="foot massage"){
		if(TP()->query_money()<300){
			write("You don't have enough for a foot massage! \n");
			return 1;
			}
		else {
		TP()->add_money(-300);
		TP()->RSP(50);
		write("As you lay down, an attendant come over and gives "+
		"you a well needed foot massage! You feel invigourated! \n");
		return 1;
		}
		}
	if(str=="2" || str=="back massage"){
		if(TP()->query_money()<500){
			write("You don't have enough for a back massage! \n");
			return 1;
			}
		else{
			TP()->add_money(-500);
			TP()->RSP(90);
			write("As you lay down, an attendant comes over and "+
			"gives you a well needed back massage, loosening all "+
			"the muscles in your back. You feel invigourated! \n");
			return 1;
		}
	}
	if(str=="3" || str=="neck rub"){
		if(TP()->query_money()<800){
			write("You don't have enough for a neck rub! \n");
			return 1;
			}
		else{
			TP()->add_money(-800);
			TP()->RSP(200);
			write("As you lay down, an attendant comes over and "+
			"gives you a well needed neck massage. You feel "+
			"totally relaxed now! \n");
			return 1;
		     }
		}
	if(str=="4" || str=="full body massage"){
		if(TP()->query_money()<1800){
			write("You don't have enough for a full body "+
			"massage! \n");
			return 1;
		   }
		else{
			TP()->add_money(-1800);
			TP()->RSP(475);
			write("As you lay down, an attendant comes over and "+
			"administers a full body massage. Your entire body "+
			"is carefully massaged. You are completely relaxed "+
			"now! \n");
			return 1;
		    }
	     }
	}
