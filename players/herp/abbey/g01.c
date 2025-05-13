#include "abbey.h"

inherit "room/room";

int door_is_open,
    door_is_found;

int push(string str) {
    if (str=="skull") {
        write("The skull doesn't move.\n");
        return 1;
    }
    return 0;
}

int touch(string str) {
    if (str=="skull") {
        if (!door_is_found) {
            say(TPN+"searches the tomb.\n");
            write("You just found a closed secret door.\n");
        }
        door_is_found=1;
        return 1;
    }
    return 0;
}

int press(string str) {

    object ob;

    if (door_is_found) {
        if (str=="eye") {
            write("Which one?\n");
            return 1;
        }
        if (str=="left eye") {
            if (door_is_open) {
                write("The door is already open.\n");
                return 1;
            }
            write("As you press the skeleton's eye, part of the altar swings to\n"+
                  "the side, revealing a secret door.\n"+
                  "The secret door is extraordinarily thick and well crafted.\n"+
                  "The door reveals a descending staircase.\n");
            say(TPN+" opens a secret door in the  altar's wall.\n");
            door_is_open=1;
            return 1;
        }
    }
    return 0;
}

int down() {
    if (door_is_open) {
        write("As you enter, the door silently closes behind you.\n");
        door_is_found=0;
        door_is_open=0;
        TP->move_player("down#"+PATH+"/g02");
        say("The door closes silently behind " + TPN + " as " + TPPRO +
            " leaves through the door.\n");
        return 1;
    }
    return 0;
}

int long(string str) {
    if (str=="door") {
        if (!door_is_open) {
            write("There is obviously no door here.\n");
            return 1;
        }
        else {
            write("The door is open.\n"); return 1;
        }
    }
// look at other items? (skull,tomb) Galadriel 15-10-1992
    if (str) {
        ::long(str);
        return 1;
    }
// end 'Galadriel'
    write(long_desc+"   There is one obvious exit: east\n");
    if (door_is_open) write("There is a doorway in the base of the altar.\n");
}

int id(string str) {
    return str=="door" || ::id(str);
}

void reset(int arg) {
    if (!arg) {
        set_light(1);
        short_desc="The Sepulcre Alcove";
        long_desc=
               "This is a small alcove off the main sanctuary. "+
               "There is a tomb with a skull motif in the " +
               "middle of the alcove.\n";
        dest_dir=({ PATH+"/e17","east" });
        items=({
           "skull","A white skull, it is almost laughing at you",
           "tomb","A black tomb, you are not sure what it contains" });
    }
}

void init() {
    ::init();
    add_action("down","down");
    add_action("touch","touch");
    add_action("press","press");
    add_action("push","push");
}

