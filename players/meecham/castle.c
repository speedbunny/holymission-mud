#define NAME "meecham"
#define DEST "/players/meecham/workroom"
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

object ob;
id(str) { return str == "castle"; }

short() {
    return "Meecham's castle";
        }

long() {
    write("Meecham's castle, what is inside remains to be seen.\n");
}

init() {
    add_action("north", "north");
}

north(str) {
  this_player()->move_player("north#/players/meecham/newbie/n14.c");
   return 1;
}

reset(arg) {
    if (arg) return;
    move_object(this_object(), DEST);
        }
make_quest() {
     ob = clone_object("obj/quest_obj");
     ob -> set_name("save_baby");
    ob -> set_short_hint("Save baby Alexander");
     ob -> set_weight(15);
     ob -> set_killing(7);
    ob->set_hint("Meecham and Kitty are in despair.  Find Meecham in his\n"+
      "tower to hear the problem and help them to regain their happiness.\n");
     ob -> add_quest();

        return 1;
}
