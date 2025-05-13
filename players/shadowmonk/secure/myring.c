inherit "obj/armour";#include "/players/shadowmonk/include/defs.h"
void reset( int arg ) {    ::reset( arg );    if(arg) return; 
    set_name
	("ring");    set_alias
	("glass ring");    set_short
	("A glass ring");    set_long
	("A simple glass ring\n");    set_weight(0);    set_value(0);    set_ac(0);    set_type("ring");}status drop() { 
    return 1; 
}void init() {    ::init();    if(!this_player()->query_immortal()) {        notify_fail("Only immortals can use this item.\n");        return 0;    }    add_action("_sbounce","sbounce");    add_action("_smas","smas");    add_action("_sbow","sbow");    add_action("_sthank","sthank");    add_action("_snod","snod");}static _sthank(str) {    if(find_living(str)) {        ltell(find_living(str),"comes in and gives a firm handshake, "+
		"exclaiming: ' Thank you.. alot!'","\n",this_player());        write("You thanked "+ capitalize(str) +".\n");        return 1;    }    notify_fail("U cannot find that player on this mud right now!\n");    return 0;}static _sbounce(str) {    if(str=="all") {        lshout("", "bounces amusedly around you... then leaves.\n",
		this_player() );        write("You bounch around everyone on the mud!\n");    return 1;    }     else if (find_living(str)) {        ltell(find_living(str),"bounches amusedly around you... "+
		"then leaves.","\n",this_player());        write("You bounch around "+ capitalize(str) +".\n");        return 1;    }    notify_fail("U cannot find that player on this mud right now!\n");    return 0;}static _smas(str) {    if(find_living(str)) {        ltell(find_living(str),"comes in and gives you a good neck "+
		"massage... then leaves quietly.","\n",this_player());        write("You massaged "+ capitalize(str) +".\n");        return 1;    }    notify_fail("U cannot find that player on this mud right now!\n");    return 0;}static _sbow(str) {    if(find_living(str)) {        ltell(find_living(str),"comes in.. bows deeply to you.. falls on "+
		"his nose and bursts into a million waterdrops.","\n",
		this_player());        write("You bowed and fell on your nose before "+CAP(str)+".\n");        return 1;    }    notify_fail("U cannot find that player on this mud right now!\n");    return 0;}static _snod() {    tell_room(environment(this_player()),this_player()->query_name()+		" nods... and says: 'Ofcourse..'\n");    write("You nod.\n");    return 1;}mixed query_auto_load() {    return "players/shadowmonk/mess/myring:";}void start() {    object p;    wear("glass ring");    write("Cloned your magic glass ring.\n");}