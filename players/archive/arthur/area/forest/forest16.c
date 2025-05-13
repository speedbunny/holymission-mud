

inherit "room/room";

reset(arg) {

    if (!arg) {

    set_light(1);
    short_desc = "The forest on Arthur's island";
    no_castle_flag = 0;
    long_desc = 
   "	You are standing in a very thick forest. As the light dances around\n"
   + "your body, you have a feeling that you are safe here. Your only wish is that\n"
   + "you would never have to leave this part of the forest again.\n"
   + "\n";
    dest_dir = ({
        "players/arthur/area/forest/forest22", "north",
        "players/arthur/area/forest/forest9", "south",
        "players/arthur/area/forest/forest15", "west",
        "players/arthur/area/forest/forest17", "east",
        });
    items = ({
     });
   }
}

