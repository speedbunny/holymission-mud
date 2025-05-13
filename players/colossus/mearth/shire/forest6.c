inherit "room/room";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "In the Hobbit forest";
    long_desc =
    "You are currently deep within the forest. The sounds of the wildlife cease\n"+
    "altogether. You dare not move in case you awaken some foul menace that lies\n"+
    "slumbering here. Exits lead north, west, and south.\n";

    dest_dir = ({
      "/players/colossus/mearth/shire/forest3", "north",
      "/players/colossus/mearth/shire/forest4", "west",
      "/players/colossus/mearth/shire/forest9", "south",
    });

    items = ({
    });
}

