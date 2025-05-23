/*
 * This "room" is a special object which can be dropped once.
 */
int dropped;
int grow_stage;
string owner;

set_owner(n) {
    owner = n;
}

reset(arg) {
    if (arg)
	return;
    dropped = 0;
    grow_stage = 5;
}

short() {
    return "portable castle";
}

long() {
    write(short() + ".\n");
}

heart_beat() {
    if (!dropped)
	return;
    if (grow_stage > 0) {
	say("The castle grows...\n");
	grow_stage -= 1;
	return;
    }
    if (grow_stage == 0) {
	string name;
	say("The portable castle has grown into a full castle !\n");
	shout("Something in the world has changed.\n");
	name = create_wizard(lower_case(owner));
	if (name)
	    move_object(name,"players/"+this_player()+"/workroom" );
	destruct(this_object());
	return;
    }
}

id(str) {
    return str == "castle";
}

drop() {
/* changed 5/25/93 James
    if (environment(this_player())->query_drop_castle()) {
*/
    if((int)environment(this_player())->query_room("no_castle_flag")) {
	write("Not this close to the city!\n");
	return 1;
    }
    dropped = 1;
    shout("There is a mighty crash, and thunder.\n");
    set_heart_beat(1);
    return 0;
}

get() {
    if (dropped) {
	write("You can't take it anymore !\n");
	return 0;
    }
    return 1;
}
