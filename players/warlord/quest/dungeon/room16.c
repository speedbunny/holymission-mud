

inherit"players/warlord/NEWSTUFF/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "forest";
    no_castle_flag = 0;
    long_desc = 
        "You can see a bright blue light coming from the south. To the north\n"
        + "it gets a lot darker. The trees seem to have eyes.\n";
    dest_dir = 
        ({
        "players/warlord/quest/dungeon/room31", "south",
        "players/warlord/quest/dungeon/room13", "west",
        });
     items=({"trees","The trees are large and brown",
         });
}

