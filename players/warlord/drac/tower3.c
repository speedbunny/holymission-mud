inherit "room/room";

reset(arg) {
    clone_list=({1,1,"great demon","players/warlord/monsters/demon3",0});

    set_light(1);
    short_desc = "tower";
    long_desc = 
    "You are in the third level of this ominous tower.. The evil presence is\n"
    + "getting a lot stronger now....... a very large demon is in your path..\n"
    + "He looks very pissed....\n";
    dest_dir = 
    ({
      "players/warlord/drac/tower2","down",
      "players/warlord/drac/towertop","up",
    });
::reset();
}

init() {
 add_action("up","up");
  ::init();
}

up() {
    if(present("great demon")) {return write("Demon says: Thou Shalt Not Pass Without Vanquishing ME!!!\n");
	return 1;}
    else {
	return !this_player()->move_player("up#players/warlord/towertop");
    }
}
