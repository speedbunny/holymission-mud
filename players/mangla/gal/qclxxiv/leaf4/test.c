int nppl;
int inbag;
object bag;
#include "/players/qclxxiv/myroom.h"
ONE_EXIT( "players/qclxxiv/test2","west",
       	 "A small storage room.\n",
       	 "A small storage room used in the building stage of the castle.\n"+
         "Obviously the temporary walls might be taken away later. You get\n"+
		 "the feeling that a much larger room is holding this one.\n", 1)

init() {
	if (!bag) bag = clone_object("/obj/container");
	else {
		if (inbag) {
			inbag = 0;
			all_out_bag();
		}
		else {
			inbag = 1;
			all_in_bag();
		}
	}
	nppl++;
	tell_object(this_player(), "You enter. "+nppl+" ppl in\n");
	tell_room(this_object(), nppl+" ppl in.\n");
	::init();
	add_action("northeast", "northeast" );
	add_action("guide", "guide" );
}
exit() {
	nppl--;
	tell_object(this_player(), "You leave. "+nppl+" ppl in\n");
	tell_room(this_object(), nppl+" ppl in.\n");
}


northeast(arg) {
	write("Going northeast again..\n");
	return 1;
}


all_in_bag() {
	int i;
	object obj;
	obj = all_inventory(this_object());
	for (i=0; i<sizeof(obj); i++)
		if (!living(obj[i])) move_object( obj[i], bag );
}

all_out_bag() {
	int i;
	object obj;
	obj = all_inventory(bag);
	for (i=0; i<sizeof(obj); i++)
		if (!living(obj[i])) move_object( obj[i], this_object() );
}

guide(arg) {
	string name;
	object guide;
	name = "wg_"+this_player()->query_name();
	if (find_living(name)) {
		tell_object(this_player(), 
					"You seem to have a guide around already.\n");
	}
	else {
		guide = clone_object("/players/qclxxiv/leaf4/guide");	
		guide->set_myman( this_player() );
		move_object( guide, this_object() );
		tell_object(this_player(), 
			"A gruffly looking man, type sturdy fisherman, appears.\n");
	}
	return 1;
}
