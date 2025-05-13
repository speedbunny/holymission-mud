inherit "room/room";

#include "/players/mangla/defs.h"


int north() {

    if("players/kelly/rooms/vill/guardroom"->open(4))
        TP->MOVEP("north#players/kelly/rooms/vill/corridor2");
    else {
        write("A grating bars your way!\n");
        say(TP->NAME + " tries to go north, but fails.\n");
    }
    return 1;
}

int search(string str) {

    if(str!="bed" && str!="plank bed") return 0;
    say(TP->NAME + " searches in the bed.\n");
    printf("You don't believe your eyes. This bed is really clean.\n");
    return 1;
}

void reset(int arg) {
    if (arg) return;
    ::reset();
    set_light(1);
    short_desc="A prison cell";
    long_desc="You're in a cell in the prison of Red Rock Junction.\n"+
              "At the cell walls there are some lines of chalk.\n"+
              "There is a plank bed standing in a corner, the window of the cell\n"+
              "is grated.\n";

    items = ({
              "wall","The is a picture of a nice lady at one wall",
              "picture","Do you think I got nothing else to do than write this silly items",
              "walls","Really dirty walls",
              "lines","You can't count them",
              "bed","A simple plank bed",
              "plank bed","A bed like in every prison",
              "window","A grating is in front of the window barring your way to liberty",
            });

    clone_list = ({ 1, 1, "enemy", "obj/monster",
                       ({ "set_name", "large troll",
                          "set_alias", "troll",
                          "set_race", "troll",
                          "set_level", 15,
                          "set_hp", 300,
                          "set_short", "A large troll",
                          "set_long", "He doesn't seem to have been here for a long time.\n",
                          "set_al", -350,
                          "set_aggressive", 1,
                          "set_size", 3,
                          "add_money", 150,
                          "set_ac", 6,
                          "set_wc", 10 })
                 });

}

void init() {
    ::init();
    add_action("north","north");
    add_action("search","search");
}

