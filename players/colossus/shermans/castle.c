#define NAME "sherman"
#define DEST "/players/sherman/workroom.c"
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
    if(this_player()->query_real_name()=="sherman") call_out("start_beep",1);
}

start_beep() {
if(present("sherman",this_object())) {
  tell_room(this_object(),"                                                                                                                               ");
  call_out("start_beep",1);
  }
}

enter(str) {
    if (!id(str))
	return 0;
    write("It is not an open castle.\n");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}

make_quest() {
    object o;

    o=clone_object("obj/quest_obj");
    o->set_name("vampirequest");
    o->set_weight(35);
    o->set_killing(10);
    o->set_short_hint("Kill the vampire king");
    o->set_hint(
"In the dark lands the evil vampire king rules a group of bloodthirsty"+
" vampires.\n"+
"Find him in the tombs beneath his tower and destroy him for ever.\n"+
"\nAttention: This is a high-level quest (25 and above)\n"+
"(Hint: Maybe a party would be handy)\n");
    o->add_quest();
}
