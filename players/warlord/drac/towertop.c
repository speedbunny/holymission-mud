

inherit "room/room";

reset(arg) {
    clone_list=({1,1,"dracula","players/warlord/monsters/dracula",0});

    set_light(1);
    short_desc = "A room";
    long_desc = 
    "You have entered the chambers of the Immortal Vampire Count Dracula..\n"
    + "His chambers is loaded with treasure depicting the dawns of time..\n"
    + "he has artifacts from all through time.. you are stunned by the sight..\n"
    + "He is practically invincible...Be warned...\n"
    + "He askes to come in and stay a while.. Maybe FOREVER!!!!!\n";
    dest_dir = 
    ({
      "players/warlord/drac/tower3","down",
    });
    ::reset();
    replace_program("room/room");
}

