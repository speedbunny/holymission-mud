

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Kkitchen";
    long_desc = 
        "This is Kirk's kitchen.\n"
        + "It smells good in here, like something was just baked.\n"
        + "There is a table in the middle of the room.\n";
items = ({"table","This is Kirk's dinner table."});    
    dest_dir = 
        ({
        "/players/jake/suite", "east",
        });
}

