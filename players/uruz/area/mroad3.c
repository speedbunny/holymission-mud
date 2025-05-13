
inherit "/players/trout/area/random_peasant";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc= "Kyoto Main Road";
	long_desc= "This is the main road of Kyoto. Buildings line both "+
	"sides of the road. Most of them are shops and small businesses. The "+
	"shop to the west is closed up, as well as the buildings to the east."+
	" To the south is the gate to Honno Ji, home of Tokugawa Ieyasu. \n";
	DD= ({ ZZ+"/mroad2", "north",
		ZZ+"/gate", "south" });
	items= ({ "shop", "A general store",
		"gate", "The only way into Honno Ji",
		"Honno Ji", "Ji is the japanese word for temple. It houses "+
		"Tokugawa and his army",
		"buildings", "Most of them are covered with boards",
		"boards", "They cover up everything, including an alley",
		"alley", "A secret alley. Maybe you should try to 'remove "+
		"boards'" });
	}
	init() {
	::init();
	AA("_remove", "remove"); }
	_remove(str){
		if(!str){
		notify_fail("Remove what? \n");
		return 0; }
		if(str=="board"||str=="boards"){
			this_player()->move_player("east#players/trout/area/"+
			"alley2");
			write("You remove the boards, and climb into the "+
			"alley. \n");
			return 1;
		}


	}
