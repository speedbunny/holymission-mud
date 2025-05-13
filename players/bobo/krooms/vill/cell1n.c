inherit "room/room";
#include "/players/mangla/defs.h"
object prisoner;
int south() {
    if("players/bobo/krooms/vill/guardroom"->open(1))
	TP->MOVEP("south#players/bobo/krooms/vill/corridor1");
    else {
        write("A grating bars your way!\n");
        say(TP->NAME + " tries to go south, but fails.\n");
    }
    return 1;
}
int search(string str) {
    if(str!="bed" && str!="plank bed") return 0;
    say(TP->NAME + " searches in whole bed.\n");
    write("You search the bed.\n" +
          "ACK!! What a creature must have slept in this bed.\n" +
          "Stains and hair cover everything. It is repulsive to say the least.\n");
    return 1;
}
void reset(int arg) {
    if (arg) return;
    set_light(1);
short_desc="A small cell.";
long_desc=
"You're in one of the cells of the prison in Red Rock Junction.  It\n"+
"is not a happy or a fun place to be.  The cell has a small bed lying\n"+
"on the floor and a grated window so that you can look out.  The only\n"+
"other thing that catches your attention is a number of white marks\n"+
"on the walls.\n";
    items=({
	"wall","Some poor soul has covered the wall with chalk waiting for his release",
            "walls","The walls are really dirty",
            "lines","You can't count them",
            "bed","A simple plank bed",
            "plank bed","A bed like in every prison",
	"grate","Strong metal bars block your way to freedom",
	"window","The window is covered with something so that you can't see past the grate",
          });
    clone_list = ({ 1, 1, "enemy", "obj/monster",
                       ({ "set_name", "public enemy",
                          "set_alias", "enemy",
                          "set_race", "human",
                          "set_level", 10,
                          "set_hp", 200,
                          "set_short", "A public enemy",
                          "set_long", "He has been arrested and incarcerated here because\n" +
                                      "he threatend the safety of the realm. He looks\n" +
                                      "deranged as he prepares to attack you.\n",
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
    add_action("south","south");
    add_action("search","search");
}
