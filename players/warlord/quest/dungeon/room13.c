

inherit"players/warlord/NEWSTUFF/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This part of the forest is very plush and dense. You can see something \n"
        + "scampering to the south of you, but the trees are to dense to go south.\n"
        + "The path continues east and west.\n";
    dest_dir = 
        ({
        "players/warlord/quest/dungeon/room4", "west",
        "players/warlord/quest/dungeon/room16", "east",
        });
       items=({"trees","You see large oak trees",
             });
}
