#include	<levels.h>

id(str) { return str=="inc"; }
short() { return "The inc"; }
long() { write("You hold the incredible Inc.\n"); }
init() { add_action("inc","inc"); }
get() { return 1; }

map_inc(object p) {

    if ((p->query_level()<=L_PLAYER) && !(p->query_incognito())) {
	write(p->query_name()+": ");
	p->incognito();
	p->save_me(1);
    }
}

inc() {
object *u;

    u=users();
    map_array(u,"map_inc",this_object());
    write("Ok.\n");
    return 1;
}
