#define NAME "kbl"
#define DEST "/players/kbl/workroom"
object taliesin;
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
    write("just the same.  You see that the gates are open, slightly.\n");
}

setup_quest()
{
  qobj = clone_object("obj/quest_obj");
  qobj->set_weight(15);
  qobj->set_name("AnySlayer");
  qobj->set_short_hint("Find AnySlayer and bring it to the Fire Elemental");
  qobj->set_hint("The Parallel Plane of Chaos is where the AnySlayer was\n"+
                 "brought to after being stolen from the Fire Elemental.\n"+
                 "A book on Chaos is known to be located inside the\n"+
                 "pyramid on top of High Cliffs, north of Kbl's castle.\n"+
                 "This quest is solvable above levels 18. Some deciphering\n"+
                 "and key observations are needed to survive the Demons Of\n"+
                 "Chaos. Good luck.\n");
  qobj->add_quest();
}

init() {
    add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
	return 0;
  this_player()->move_player("into Kbls' castle#players/kbl/kblroom");
    return 1;
}

reset(arg) {
    if (arg)
	return;
    transfer(this_object(), DEST);
    if(!taliesin)
    {
      taliesin = clone_object("players/kbl/guild/taliesin");
      transfer(taliesin,"room/pub2");
      log_file("kbl.taliesin","Taliesin created and moved at "+ctime(time())+" ***\n");
    }
}
