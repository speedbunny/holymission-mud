/* l01 */
#include "/players/qclxxiv/leaf5/leaf5room.h"

object herb;
int wallopen;
set_wallopen(i) {
	wallopen=i;
	if (i) 
		tell_room(this_object(),
"Suddenly, an opening in the wall appears to the east...\n" );
	else
		tell_room(this_object(),
"Suddenly, the opening in the wall to the east disappears...\n" );
}

query_qnewbie() { return 1; }
TWO_EXIT( REGION+"l04", "northwest",
REGION+"l02", "northeast",
"Inside a shady room", "",
1 )

long(arg) {
	if (!arg) {
		write(
	"Inside a dark maze. A buckler is hanging against the eastern wall.\n");
		::long(arg);
		if (wallopen)
			write("    and a dark opening: east\n");
	}
	else ::long(arg);
}

init() {
   ::init();
	add_action("press", "press");
	add_action("press", "push");
	add_action("to_circ5", "east");
}

extra_reset(arg) {
	if (random(5)==3) {
			FRESH_IN_THIS(herb, REGION+"ironweed");	
	}
   if (arg) return;
    set_nodig(1);
   items = ({
				"buckler",
"A small buckler, featuring a blue cross dividing it into four quadrants. In\n"
+"them: a seven-fingered leaf, a lion, a six-pointed star, and a book",
				"wall", "Old dark wall",
   });
			/* to HOME+"circular/circ5", "east", */
}

   /* 
do_get( arg ) {
   if (!arg) return 0;
   switch (arg) {
       case "street" : write("How do you plan to carry that?\n"); break;
       default: return 0;
   }
   return 1;
}
   */ 

press(str) {
	string thing;
	if (sscanf(str, "%s", thing)) {
		if (thing=="buckler") {
			say(this_player()->query_name()+" presses the buckler.\n",
						this_player() );
			if (!wallopen) {
				set_wallopen(1);
				call_other( HOME+"circular/circ5", "set_leftwallopen", 1);
				call_out("close_wall", 10);
			}
			return 1;
		}
	}
	return 0;
}

close_wall() {
	if (!wallopen) return;
	set_wallopen(0);
	call_other( HOME+"circular/circ5", "set_leftwallopen", 0);
}

to_circ5(arg) {
	if (wallopen) {
		this_player()->move_player("east",HOME+"circular/circ5");
		close_wall();
		return 1;
	}
	return 0;
}
