

inherit "room/room";

reset(arg) {

    if (!arg) {

    set_light(1);
    short_desc = "Outside forest, looking at ocean.";
    no_castle_flag = 0;
    long_desc = 
   "You are standing on a sandy beach. The waves roll in and hit the edge\n"
   + "of the beach very hard. You can see the forest back to your southwest, and southeast.\n"
   + "\n";
    dest_dir = ({
        "players/arthur/area/forest/forest21", "southwest",
        "players/arthur/area/forest/forest23", "southeast",
        });
    items = ({
     "sand",
     "The sand is very smooth, as you walk it caresses your feet making them feel\n"
     + "much better than normal.\n"
     + "",
     "waves",
     "The waves are rolling in with trememdious power, making you feel that\n"
     + "it would not be a good idea to try to enter here.\n"
     + "",
     });
   }
}

