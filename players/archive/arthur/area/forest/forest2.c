

inherit "room/room";

reset(arg) {

    if (!arg) {

    set_light(1);
    short_desc = "A forest on Arthur's island.";
    no_castle_flag = 0;
    long_desc = 
   "	You are standing in a very thick forest. As the light dances around\n"
   + "your body, you have a feeling that you are safe here. You only wish that\n"
   + "you would never have to leave this forest again.\n"
   + "\n";
    dest_dir = ({
        "players/arthur/area/forest/forest10", "north",
        "players/arthur/area/forest/forest1", "west",
        "players/arthur/area/forest/forest3", "east",
        });
    items = ({
     });
   }
}

