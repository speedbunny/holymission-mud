#define NAME "sarge"
#define DEST "/players/sarge/workroom"
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
    return "Sarge's castle";
        }

long() {
    write("Sarge's castle, what is inside remains to be seen.\n");
}

init() {
    add_action("north", "north");
}

north(str) {
   this_player()->move_player("leaves north#players/sarge/rooms/room1");
   return 1;
}

reset(arg) {
    if (arg) return;
    move_object(this_object(), DEST);
        }
make_quest() {
     ob = clone_object("obj/quest_obj");
     ob -> set_name("heart");
     ob -> set_short_hint("Return Abduhla's heart.");
     ob -> set_weight(15);
     ob -> set_killing(5);
     ob->set_hint("Long ago the Denizen killed the mighty warrior, Abduhla\n"+
                    "Gravis, and kept his heart as a memento. Abduhla calls\n"+
                    "forth, from the grave, for the return of his heart.\n");
     ob -> add_quest();

        return 1;
}
