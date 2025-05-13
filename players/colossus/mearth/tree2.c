/* Galadriel 17-JUN-94: fixed climb, room did not load */
#include "mroom.h" // moonie 110883 no ;'s after #-directives please

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Top of Tree of Time and Space";
    long_desc = 
    "This is the top of the Tree of Time and Space. Now that you're closer\n"+
    "you realize that the branches just stretch as far as the eyes can see\n"+
    "and taper off. Legend says that you can enter the realm of Middle Earth\n"+
    "by following the branch that has rings carved into it. The other branches\n"+
    "lead back to the shop and church. There is a particularly long branch\n"+
    "that leads further up the tree.\n";

    dest_dir = ({
      MET+"/start", "rings",
      "/room/church", "church",
      MET+"/tree1", "down",
       "/players/nae/guild/room", "vagabonds",
      "/room/main_shop", "shop",
    "/players/nylakoorub/4th/portal","up",
    });
    items = ({
      "branches", "They are big, thick, and strong and go as far as your eye can see",
      "branch", "A particularly long branch that leads steaily upwards",
    });
}

void init(){
    ::init();
/*
    add_action("climb", "climb");
*/
}

/* Galadriel 17-JUN-94: int ==> mixed, notify_fail is not int */
/***** Remove to place in simple exit   Mangla ******
mixed climb(string str){
    if(!str || str!="branch")
	return notify_fail("Climb what?\n");
    write("You start climbing up the branch.\n");
    say(this_player()->query_name()+" starts climb up.\n");
    call_out("stage2", 3);
    return 1;
}

void stage2(){
    write("You finally reach the tip of the branch.\n");
    say(this_player()->query_name()+" is near the tip of the branch.\n");
    call_out("stage3", 1);
    return;
}

void stage3(){
    this_player()->move_player("up#/players/nylakoorub/guild/rooms/portal");
}
***************************/
