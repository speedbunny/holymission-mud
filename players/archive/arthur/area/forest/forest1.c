

inherit "room/room";

reset(arg) {

    if (!arg) {

    set_light(1);
    short_desc = "A forest on Arthur's island";
    no_castle_flag = 0;
    long_desc = 
   "	You are in a very thick forest, the light is sparkling all around you\n"
   + "creating the feeling of peace in this part of the forest. As you look back to\n"
   + "south, you can see a town.\n"
   + "\n";
    dest_dir = ({
        "/players/arthur/area/forest/forest9", "north",
        "players/arthur/area/forest/forest4", "west",
        "/players/arthur/area/forest/forest2", "east",
        "/players/arthur/entrance", "south",
        });
    items = ({
     });
   }
}

