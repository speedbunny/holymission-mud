#include "path.h"
#define FILENAME "/players/danford/obj/deck:"

inherit "obj/treasure";

int drop() {
	return 1;
}

string query_auto_load() {
	return FILENAME;
}
 
init () {
::init();
add_action("ollie", "ollie");
add_action("grind", "grind");
add_action("show", "show");
add_action("kickflip", "kickflip");
add_action("shoveit", "shoveit");
add_action("stalefish", "stalefish");
add_action("halfcab", "halfcab");
add_action("feeble", "feeble");
add_action("cab", "cab");
add_action("handplant", "handplant");
add_action("impossible", "impossible");
}
 
ollie() {
     write("You do a gigantic ollie.\n");
     say(this_player()->query_name()+ " does a gigantic ollie over your head.\n");
     return 1;
}
 
grind() {
     write("You do a 50-50 grind on a nearby steel pipe.\n");
     say(this_player()->query_name()+ " does a 50-50 grind on a nearby steel pipe.\n");
     return 1;
}
 
show() {
     write("You proudly show off your skateboard.\n");
     say(this_player()->query_name()+ " proudly shows off "+ this_player()->query_possessive()+ " skateboard.\n");
     return 1;
}
 
kickflip() {
     write("You do a 360 kickflip to the amazement of the gathering crowd.\n");
     say(this_player()->query_name()+ " does a difficult 360 kickflip, to the amazement of the gathering crowd.\n");
     return 1;
}
 
shoveit() {
     write("You do a 540 shove-it to manual.  Quite impressive.\n");
     say(this_player()->query_name()+ " does a 540 shove-it to manual.\nYou are quite amazed.\n");
     return 1;
}
 
stalefish() {
     write("You launch a stalefish air on a halfpipe that just happened to be lying around.\n");
     say(this_player()->query_name()+ " launches a stalefish air on a halfpipe that just happened to be lying around.\n");
     return 1;
}
 
halfcab() {
     write("You pop a quick half cab.  No biggie.\n");
     say(this_player()->query_name()+ " pops a quick half cab.\nAlthough it would be amazing if you did it, it is nothing for this skater.\n");
     return 1;
}
 
feeble() {
     write("You do a quick feeble grind on a nearby curb.\n");
     say(this_player()->query_name()+ " does a quick feeble grind on a curb that you hadn't noticed before.\n");
     return 1;
}
 
cab() {
     write("You ollie a one-footed frontside caballerial.  Wow!\n");
     say(this_player()->query_name()+ " ollies a one-footed frontside caballerial.  WHOA!\n");
     return 1;
}
 
handplant() {
     write("You do a fresh handplant on the pavement.\n");
     say(this_player()->query_name()+ " does a fresh handplant on the pavement.\n");
     return 1;
}
 
impossible() {
     write("You launch a one-footed ollie impossible to board on a nearby bench.\nDamn, that's nearly impossible!\n");
     say(this_player()->query_name()+ " launches a one-footed ollie impossible to board on a nearby bench.\nThat's damn near IMPOSSIBLE!\n");
     return 1;
}
 
reset(arg) {
     set_id("skateboard");
     set_alias("skate");
     set_short("Danford's Skateboard");
     set_long("It has loose trucks and VERY small wheels, just like Danford likes it.\n"+
     "Avaliable Skate Commands are:\n"+
     " ollie\n"+
     " grind\n"+
     " show\n"+
     " kickflip\n"+
     " shoveit\n"+
     " stalefish\n"+
     " halfcab\n"+
     " feeble\n"+
     " cab\n"+
     " handplant\n"+
     " impossible\n"+
     "");
     set_weight(1);
     set_value(1000);
}
