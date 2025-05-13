inherit "/room/room";

#include "/players/mangla/defs.h"
status rope;

int _climb(string item) {
   if(item!="down rope" && item!="down the rope") return 0;
  if(rope) {
	write("The stream is too fast.  You are pulled away from the bank.  "+
	      "You are left swimming in a quiet part of the river until "+
              "catching an eddy and pulling yourself up to the shore.\n");
	TP->MOVEP("down the rope#players/bobo/krooms/wastelands/shore1");
   }
   else
        write("Maybe you should tie the rope to the bridge first.\n");
   return 1;
}

int_tie(string str) {
   if(str!="rope to bridge" && str!="rope onto the bridge") return 0;
   write("You take the rope and securely tie it to the bridge, and dangle "+
	 "the other end over the side.\n");
   rope=1;
   return 1;
}

int _untie() {

    write("You untie the rope, coil it up, and place it beside the bridge.\n");
    rope = 0;
    return 1;
}

int _get(string str) {

    if (str == "rope") {
        write("You can tie the rope to the bridge, but you cannot get it.\n");
        return 1;
    }
    return 0;
}


void reset(int arg) {

    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="On a bridge";
    long_desc="You are standing on a bridge over the fast-flowing Quiet River.\n"+
              "Down below, you can see the water flow swiftly past. There is a rope\n" +
              "lying on the ground near the bridge that you might be able to use\n" +
              "to climb down with if it was tied to the bridge.\n";
    dest_dir=({
		"players/bobo/krooms/mythwood/mythpath5","east",
		"players/bobo/krooms/mythwood/plateau","west",
             });
    items=({"bridge","A wooden bridge spanning the quiet river",
            "rope",  "A rope that could be used to climb down"
          });
}

void init() {
    ::init();
    add_action("_climb","climb");
    add_action("_untie","untie");
    add_action("_tie","tie");
    add_action("_get","get");
    add_action("_get","take");
}

