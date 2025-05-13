#define NAME "shaka"
#define DEST "/players/shaka/workroom"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to desert/design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

id(str) { return str == "castle"; }

short() {
    return("To the south is a small path running through the mountains\n" +
           "besides the road stands a sign");
}

long() {
   write("Small letters on the sign say:\n"+
         "follow this path south to the land of shaka\n"+
         "but beware dont go off the trail while in the \n"+
         "mountains \n");
}

init() {
    add_action("move"); add_verb("south");
    add_action("read"); add_verb("read");
    add_action("read"); add_verb("look");
}

move() {
    object ob;
    call_other(this_player(),"move_player", "south" + "#" + "players/shaka/mountain/path1");
    return 1;
}

read(str) {
    if (str == "sign" || str == "at sign") {
	long();
	return 1;
    }
}


reset(arg) {
    if (arg)
	return;
    transfer(this_object(), DEST);
}
