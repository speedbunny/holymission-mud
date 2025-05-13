#include "mroom.h" // moonie 110883 no ;'s after #-directives please

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Top of Tree of Time and Space";
    long_desc = 
    "This is the top of the Tree of Time and Space. Now that you're closer\n"+
    "you realize that the branches just stretch as far as the eyes can see\n"+
    "and taper off. Legend says that you can enter the realm of Middle Earth\n"+
    "by following the branch that has rings carved into it. The other branches\n"+
    "lead back to the shop and church.\n";

    dest_dir = ({
      MET+"/start", "rings",
      "/room/church", "church",
      MET+"/tree1", "down",
      "/room/main_shop", "shop",
    });
}

init(){
    ::init();
    add_action("up", "up");
}

up(){
    write("You start climbing up the branch.\n");
    say(this_player()->query_name()+" starts climb up.\n");
    call_out("stage2", 3);
}

stage2(){
    write("You finally reach the tip of the branch.\n");
    say(this_player()->query_name()+" is near the tip of the branch.\n");
    call_out("stage3", 1);
}

stage3(){
    this_player()->move_player("up#/players/colossus/guild/portal");
}
