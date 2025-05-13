#define NAME "haplo"
#define DEST "/players/haplo/workroom"
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

inherit "room/room";

reset(arg) {
    if(arg) {
        set_light(1);
        short_desc="Castle of " + NAME;
        long_desc=
            "This is the "+short_desc+".\n"+
            NAME + " is a rather new wizard, but it is an amazing castle\n"+
            "just the same. However, the gates are closed.\n";
        items=({ 
            "castle","@@short",   /* we need that to get the 'castle' id */
              });
    }
   /*
    "/players/patience/ezo/coast/sh14"->short();
//     "/players/haplo/ishikawa/jungle/beach1"->short();
    move_object(this_object(), DEST);
      sampan was removed so pthis prevents bugs-haplo 3-23-95 */
}

make_quest() {
object quest;
quest = clone_object("obj/quest_obj");
quest->set_name("serpent_king");
quest->set_weight(30);
quest->set_killing(9);
quest->set_short_hint("Quest for the Crown of Ishikawa");
quest->set_hint("The Great Eastern Serpent Kyoshi has taken the Crown of\n"+
                "Ishikawa which the villagers there hold most sacred.  The\n"+
                  "village elder is seeking an honorable adventurer to slay\n"+
	          "the evil Serpent and pry the Crown from the claws of this\n"+                  "venomous beast.\n");
quest->add_quest();
move_object(this_object(), DEST);
}
init() {
    ::init();
    add_action("enter", "enter");
}

enter(str) {
    if (!id(str))
	return 0;
    write("It is not an open castle.\n");
    return 1;
}
