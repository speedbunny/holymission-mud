#include "/players/qclxxiv/root/rootroom.h"
int lastc;

extra_reset(arg) { 
	mayexit = 0; /* any reset of course */
	if (arg) return; 
	items = ({ 
			"board", 
"\n Root workers can not leave the premises until all eelworms have been \n exterminated.\n Please don't try to use teleport facilities of any kind.\n In the room west from here weapons can be obtained if needed,\n and some light administrative work can be done by harmed workers.\n		The director of root maintenance.\n"
+"For workers up to level 5 there is an escape route though to the east",
				"lanthorns", 
"Shining copper oil-burning lanthorns, spreading their yellowish light",
			});
	property=({ "has_fire" });
	mayexit = 0; 
	return 1; 
}

light_text(str) {
	write("You light the "+str+" on one of the lanthorns.\n");
	say(this_player()->query_name()+" lights a "+str+",\n"
			+ "on one of the lanthorns.\n");
}

ONE_EXIT(	ROOT+"work","west",
"In the root workers' entrance",
"You are now an official root worker in the giant leaf's root system!\n"+
"You find yourself in the root workers' entrance room. After all the\n"+
"eelworms in the root system have been eliminated by the workers, the\n"+
"workers can leave north here again. It's a good idea to try and get more\n"+
"workers in, as together you will do the job faster of course. Lanthorns are\n"+
"spreading their yellowish light. A board shows some instructions to root\n"+
"workers, maybe you should look at it?\n\tExit to the shop: north.\n"
, 1)

init() {
	object I;
	::init();
	add_action("north","north");
	add_action("east","east");
	if (I = find_player("qclxxiv")) {
		if (I!=this_player()) {	
			tell_object(I, ">>>>>>>>>>>>> "+
				this_player()->query_name()+" entered the rootsystem.\n");
		}
	}
}

north(arg) {
	/* only if all eelworms in all rooms are gone, leaving north is allowed*/
	
	if (!all_eelworms_killed() && !this_player()->query_ghost() ) {
		say(this_player()->query_name()+" tries to leave the root system.\n");
		write("You can't leave yet, there are still eelworms in the roots!\n");
		return 1;
	}
	write("Well all right, thank you for your contribution.\n");	
	say(this_player()->query_name()+" is allowed to leave the root system.\n");
	this_player()->move_player("north#/players/qclxxiv/root/enter");
	return 1;
}


east(arg) {
	/* it appeared to be too hard for low level players   */
	
	if (this_player()->query_level() > 5) {
		say(this_player()->query_name()+" tries to leave the root system.\n");
		write("You can't leave this way, it's a newbie escape route!\n");
		return 1;
	}
	write(
	"Well all right, as you are still low in level we'll have some pity.\n");	
	write("You are transported to somewhere else.\n");
	say(this_player()->query_name()+" is allowed to leave the root system.\n");
	this_player()->move_player("east#/players/qclxxiv/leaf1/l5");
	return 1;
}

all_eelworms_killed() {
	int t;
	string aline;
	object aroom;
	for (t=1; t<=23; t++) {
		aline = ROOT+"w"+t;
		/* write("checking "+aline+"\n"); */
		aroom = find_object(aline);
		if (!aroom) {
			call_other(aline,"nonexistingfunction"); /* force load */
			aroom = find_object(aline);
		}
		if (present("eelworm",aroom)) return 0; /* still worms alive */
	}
	mayexit = 1;
	return 1;
}

