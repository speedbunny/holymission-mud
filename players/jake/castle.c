#define NAME "jake"
#define DEST "/players/jake/workroom.c"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return str == "castle"; }

short() {
    return "Castle of " + NAME;
}

long() {
    write("This is the " + short() + ".\n");
    write(NAME + " is a rather new wizard, but it is an amazing castle\n");
    write("just the same. However, the gates are closed.\n");
}

init() {
    add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
	return 0;
    write("It is not an open castle.\n");
    return 1;
}

reset(arg) {
object sgn;

    if (!arg) {
      move_object(this_object(), DEST);
/*
      move_object(sgn=clone_object("/obj/thing"),"room/forest8"); 
      sgn->set_name("sign");
      sgn->set_short("A sign");
      sgn->set_long("A beautiful sign pointing north.\n");
sgn->set_read("To the north is Jake's Place.\nIt is now open for everyone.\nGo scheck it out!\nComing soon:\nGoblin-Ville!\n");
      sgn->set_can_get(0);
*/
    }
}
