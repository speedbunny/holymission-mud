inherit "/players/trout/area/random_guard";
#include "/players/trout/defs.h"


reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="Tearoom";

	long_desc="A tea room dominates the scene here. The table is "+
	"surrounded by small stools. A staircase is visible at the south "+
	"end. A doorway leads east to a room filled with books. On the west"+
	" wall a large piece of paper hangs.\n";
	DD= ({ ZZ+"/recept", "north",
		ZZ+"/servant1", "west",
		ZZ+"/gallery", "stairs",
		ZZ+"/library", "east" });
	items= ({ "table", "Several teacups fill the low tea table",

		"teacup", "Hand-painted teacups with the name 'Kobiashi' "+
		"written on the bottom",
		"paper", "It has writing on it. Try reading it!",
		"stool", "A padded kneel stool. Very comfortable" });
	::reset(arg);
	}
init(){
	::init();
	AA("_read", "read");
	}
int _read(string arg){
	if(arg=="paper"){
		write("		A Warrior's Creed\n"+
		"I have no parents-I make the heavens and earth my parents.\n"+
		"I have no home- I make awareness my home.\n"+
		"I have no life or death- I make the tides of breathing my "+
		"life and death.\n"+
		"I have no divine power- I make honesty my divine power.\n"+
		"I have no means- I make understanding my means.\n"+
		"I have no magic secrets- I make character my magic secret.\n"+
		"I have no body- I make endurance my body.\n"+
		"I have no eyes- I make the flash of lighting my eyes.\n"+
		"I have no limbs- I make promptness my limbs.\n"+
		"I have no strategy- I make 'unshadowed by thought' my "+
		"strategy\n"+
		"I have no designs- I make 'siezing opportunity by the "+
		"forelock' my design\n"+
		"I have no miracles- I make right-action my miracles.\n"+
		"I have no principles- I make adaptibility to all circum"+
		"stances my principles.\n"+
		"I have no tactics- I make emptiness and fullness my "+
		"tactics.\n"+
		"I have no talents- I make ready wit my talent.\n"+
		"I have no friends- I make my mind my friend.\n"+
		"I have no enemy- I make carelessness my enemy.\n"+
		"I have no armor- I make benevolence and rightousness "+
		"my armor. \n"+
		"I have no castle- I make immovable-mond my castle.\n"+
		"I have no sword- I make absence of self my sword.\n"+
		"			-Anonymous Samurai\n");
		return 1;}
	}
