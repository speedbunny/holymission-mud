inherit "obj/monster";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("calvary");
	set_alias("horse");
	set_al(110);
	set_level(30+RAN(6));
	set_hp(4000);
	set_race("calvary");
	set_short("Tokugawa's Calvary");
	set_long("This is a member of Daimyo Tokugawa's Calvary. A "+
	"powerful samurai sits upon a magnificent horse! A fearsome "+
	"sight!\n");
	set_wc(39);
	set_aggressive(1);
	set_ac(29);
	return;
	}
	
hit_player(dam){
	switch(RAN(3)){
		case 0:
			write("The calvary charges you with lightning "+
			"speed! He hits you full force!\n");
			say("The calvary charges "+TP()->QRN()+" with "+
			"lightning speed! He hits "+TP()->QRN()+" with "+
			"full force!\n");
			TP()->hit_player(65);
			break;
		default: break;
		}
	return ::hit_player(dam);
	}
