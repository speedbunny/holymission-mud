

inherit"players/warlord/NEWSTUFF/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "forest";
    no_castle_flag = 0;
    long_desc = 
        "You start to feel happy right now. The blue light is even brighter\n"
        + "here. You can see a white figure off to the west\n";
    dest_dir = 
        ({
        "players/warlord/quest/dungeon/room16", "north",
        "players/warlord/quest/dungeon/room32", "south",
        });
    items=({"figure","The figure looks like a white horse",
         });
}

