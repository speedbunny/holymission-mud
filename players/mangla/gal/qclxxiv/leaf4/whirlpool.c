#include "/players/qclxxiv/myroom.h"
object destination;
string throwout_mssg;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

NO_EXIT( "An utterly strong whirlpool",
       	 "An utterly strong whirlpool sucks you in.\n"
		 +"You can't do a thing as you get sucked in deeper and deeper.\n", 1)

extra_reset(arg) {
	if (!destination) destination = "/players/qclxxiv/leaf4/t_3_0";
}

init() {
	::init();
	call_out("suck",2);
}

suck() {
	if (throwout_mssg) tell_room(this_object(), throwout_mssg );
	else tell_room(this_object(),
			"You get sucked into the whirlpool deeper and deeper.\n");
	throw_all_out();
}

throw_all_out() {
	int i,j;
	object obj, pobj;
	obj = all_inventory(this_object());
	for (i=0; i<sizeof(obj); i++) {
		if (living(obj[i]) && !(obj[i]->query_npc()) && random(10)>6 ) {
			pobj = all_inventory(obj[i]);
			for (j=0; j<sizeof(pobj); j++) {
				if (!(pobj[j]->id("exsoul")) && pobj[j]->get()
					&& !(pobj[j]->drop()) && pobj[j]->short()) {
					transfer(pobj[j], this_object() );
					if (!pobj[j]) break;	
					tell_object(obj[i],"You loose "+
								lower_case(pobj[j]->short()) +".\n");
					if (random(10)>6)
						destruct(pobj[j]);
					else move_object( pobj[j], destination );
					break;
				}
			}
		}
		move_object( obj[i], destination );
	}
}
