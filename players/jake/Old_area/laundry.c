

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(2);
    short_desc = "laundry";
    long_desc = 
        "You have entered the laundry room.\n"
        + "There are a few old buckets, and clothes strewn about.\n"
        + "This is where Jake does his laundry.\n";
    dest_dir = 
        ({
        "/players/jake/basee.c", "east",
        });
}

