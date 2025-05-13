#include "room.h"
#define HOME "players/qclxxiv/"

int nodig;
set_nodig(i) { nodig = i; } /* to disallow digging in a myroom: set to 0 */
/* To make something be found if a player digs: provide a dig(playerobj) */
/*	other than the default one (see below). */

its_a_qclxxiv_room() { return 1; }

/* place_in_room should be used via PLACE_IN_ROOM macro: see myroom.h
// usage: PLACE_IN_ROOM(objvarname, filename)
*/
place_in_room( objname, filname, roomname  )
{
	if (!objname) {
		objname = clone_object(filname);
    	move_object(objname, roomname);
    }
	return objname;
}

/* fresh_in_room should be used via FRESH_IN_ROOM macro: see myroom.h
// usage: FRESH_IN_ROOM(objvarname, filename)
*/
fresh_in_room( objname, filname, roomname  )
{
	if (!objname  || environment(objname)!=this_object() ) {
		objname = clone_object(filname);
    	move_object(objname, roomname);
    }
	return objname;
}

/* make_in_room should be used via MAKE_IN_ROOM macro: see myroom.h
// usage: PMAKE_IN_ROOM(filename)  (returns objectptr like place_etc,
// but requires no varname).
*/
make_in_room( filname, roomname  )
{
	object objname;
	objname = clone_object(filname);
    move_object(objname, roomname);
	return objname;
}

is_nodig() {
	return nodig;
}

dig(player) {
	if (is_nodig() ) return 0;
	return "You find nothing.\n";
}

ext_long(arg) {
	if (!arg) arg = this_object();
	arg->long();
	show_inventory(arg);
}

show_inventory(arg) {
	int i;
	object obj;
	if (!arg) arg = this_object();
	obj = all_inventory(arg);
	for (i=0; i<sizeof(obj); i++)
		if (obj[i]->short()) write(capitalize(obj[i]->short())+".\n");
}

show_inventory_pl(arg, tp) {
	int i;
	object obj;
	if (!arg) arg = this_object();
	obj = all_inventory(arg);
	for (i=0; i<sizeof(obj); i++) {
		if (tp==obj[i]) continue;
		if (obj[i]->short()) write(capitalize(obj[i]->short())+".\n");
	}
}

/* qinscription writes (to this_player) the standard message about
// not being able to read a qinscription. Call at all read_inscriptions
// of players for whom that inscription is not intended: don't use arg then.
// If arg is set non-0, i.e. to a string, the player WILL be able to read the
// inscription, which should be placed in the string then.
*/
qinscription(arg) {
	write(
"The inscription is written in very special magic symbols. It is one of\n"+
"those messages that can only be understood by certain intended persons or\n"+
"intended groups of persons. The art of making such messages has been long\n"+
"and successfully employed by the Q's of the lengthy Q dynasty, as you \n"+
"remember now.\n");
	if (!arg) {
		write(
"As you can't make anything out of the weird symbols, you conclude that this\n"
+"inscription carries no message meant for you.\n");
	}
	else {
		write(
"As you peer at the weird symbols, you get a strange feeling about you and\n"+
"all at a sudden the text becomes crystal clear. It reads:\n");
		write(arg);
	}
}
