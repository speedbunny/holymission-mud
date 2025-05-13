inherit "room/room";
#include "/players/mangla/defs.h"
object prisoner;
int north() {
    if("players/bobo/krooms/vill/guardroom"->open(2))
	TP->MOVEP("north#players/bobo/krooms/vill/corridor1");
    else {
        write("A grating bars your way!\n");
        say(TP->NAME + " tries to go north, but fails.\n");
    }
    return 1;
}
int search(string str) {
    if(str!="bed" && str!="plank bed") return 0;
    say(TP->NAME + " searches the bed.\n");
    write("You can't believe your eyes. This bed is actually clean.\n");
    return 1;
}
reset(arg) {
    if (arg) return;
    set_light(1);
short_desc="A small cell.";
long_desc=
"You're in one of the cells of the prison in Red Rock Junction.  It\n"+
"is not a happy or a fun place to be.  The cell has a small bed lying\n"+
"on the floor and a grated window so that you can look out.  There are\n"+
"a bunch of white marks on all the walls here, also there is a small\n"+
"tattered picture on the wall near the bed.\n";
    items = ({
              "wall","There is a picture of a nice lady on one wall",
              "picture","Shown here is a noble lady in a red dress",
              "walls","Really dirty walls",
              "lines","You can't count that high",
              "bed","A simple plank bed",
              "plank bed","A bed similar to almost every prison you have seen",
              "window","A grating is in front of the window and bars the way to liberty",
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
    ::reset();
}
init() {
    ::init();
    add_action("north","north");
    add_action("search","search");
}
