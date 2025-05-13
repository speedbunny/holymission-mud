

inherit "room/room";

reset(arg) {
    clone_list=({1,1,"demon","players/warlord/monsters/demon1",0});

    set_light(1);
    short_desc = "A room";
    long_desc = 
    "This is the ground floor of the Dark Tower.... you see something lurking in \n"
    + "the shadows, it looks like a small demon....\n";
    dest_dir = 
    ({
      "players/warlord/drac/grave9","south",
      "players/warlord/drac/tower2","up",
    });
    ::reset();
    replace_program("room/room");
}

