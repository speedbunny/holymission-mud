#define NAME "Warlord"
#define DEST "players/warlord/workroom"
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
    if(arg) return;
    /* old version
    call_other("/players/warlord/sign.c","/room/hump");
    call_other("/players/warlrod/trans/drag.c","/players/warlord/trans/port1");
    */
    /* NEW VERSION */
    /* first we load the item by calling a non-existing function in it */
    "/players/warlord/sign"->xxx();
    /* then we find it and move it where we need it */
/*
     if (!find_object("/players/warlord/trans/drag"))
     {
         catch(call_other("/players/warlord/trans/drag","???"));
         move_object(find_object("players/warlord/trans/drag"),
      "/players/warlord/trans/port1");
     }

// Mangla: TEMP FOR TESTING
    "players/warlord/trans/port1"->xxx();
*/
    move_object(this_object(),DEST);
}
make_quest() {
    object orb;
    orb=clone_object("/obj/quest_obj");
    orb->set_name("orb_quest");
    orb->set_short_hint("Help find the orb and bring it to the monk.");
    orb->set_weight(40);
    orb->set_hint("Help the monk find the orb that the dragon keeps.\n"
      + "Be careful though, for the dragon hides well.\n"
      + "Use your wits.\n");
    orb->set_killing(9);
    orb->add_quest();
}
