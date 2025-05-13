

inherit"players/warlord/NEWSTUFF/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A plush forest";
    no_castle_flag = 0;
    long_desc = 
          "The trees seem closer together here. The breeze here feels cool\n"
            +"on your face. The sun feels very warm but you get a bad feeling\n"
         +" that something bad is about to happen.\n";
    items = ({
          "trees", "The trees are very large, plush and dense.",
          "sun", "The sun is bright orange, it almost hurts to look at it",
          });
    dest_dir = 
        ({
        "players/warlord/quest/dungeon/room1", "south",
        "players/warlord/quest/dungeon/room4", "north",
        });
}

