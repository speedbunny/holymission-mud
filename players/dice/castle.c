#define NAME "dice"
#define DEST "/players/dice/workroom.c"
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
/*   removed from list for gambit's quest...feel free to recode it
make_quest() {
  object quest;
  quest = clone_object("obj/quest_obj");
  quest->set_name("earth_quest");
  quest->set_weight(8);
  quest->set_killing(1);
  quest->set_short_hint("Free the man held captive by the earth powers");
 quest->set_hint("Free the little man that is held captive by the powers of the earth.\n"+
             "Have fun.\nCoffee-addicted Dice\n");
  quest->add_quest();
  move_object(this_object(), DEST);
} */
