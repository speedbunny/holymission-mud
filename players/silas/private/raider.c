inherit "obj/monster";
#include "/players/akira/define.h"
reset(arg){
	::reset(arg);
	if(arg) return;

	set_name("temporal raider");
	set_alias("raider");
	set_long("This is an Evil Timelord, that has left the vagabond guild."+
         "He now uses his powers to raid into other dimensions to steel\n"+
         "and kill those weaker than himself. Should he ever run into a\n"+
         "member of the Vagabond Guild, he would take great pleasure in\n"+
         "ripping there heat out!\n");
	set_level(80);
	set_wc(100);
	set_number_of_arms(4);
	set_ac(100);

	set_al(-500);
	set_aggressive(1);
}
init(){
	::init();
	AA("block", "peace");
	AA("block", "zap");
	AA("block", "update");
	AA("block", "destruct");
	AA("block", "home");
	AA("block", "goto");
	AA("block", "heal");
	AA("block", "clean");
	AA("block", "uphere");
	}
block(arg){
	if(query_verb()=="peace"){
		write("The temporal raider isn't interested in making "+
		"peace!\n");
		return 1;
		}
	if(query_verb()=="destruct"){
		if(arg=="raider" || arg=="temporal raider"){
		   write("The temporal raider doesn't like it when you "+
		   "try to destruct him!\n");
		    return 1;
		    }
		}
	if(query_verb()=="home"){
		write("The temporal raider won't let you go home until "+
		"you finish this fight!\n");
		return 1;
		}
	if(query_verb()=="zap"){
		if(arg=="raider" || "temporal raider"){
			write("You try to zap the temporal raider, but "+
			"gets pissed, and backhands you!\n");
			return 1;
			}
		}
	if(query_verb()=="goto"){
			write("The temporal raider won't let you go "+
			"anywhere until your done fighting!\n");
			return 1;
		}
	if(query_verb()=="update"){
		write("The temporal raider smacks you for trying to update "+
		"anything!\n");
		return 1;
		}
	if(query_verb()=="clean"){
		write("That's right, the raider came here to clean house!\n");
		return 1;
		}
	if(query_verb()=="uphere"){
		write("The temporal raider gets mad when you try to update "+
		"the environment on him!\n");
		return 1;
		}
	if(query_verb()=="heal"){
		write("The temporal raider thinks you don't need to heal!\n");
		return 1;
		}
	}
