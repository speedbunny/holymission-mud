

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "The entrance to the Sorceror's lair";
    no_castle_flag = 0;
    long_desc = 
        " This is the entrance to the Realm of Night. The monsters in here \n"
       +" are not for the faint of heart. So be forewarned of the impending \n"
        +" DANGERS!!!!! \n";
    dest_dir = 
        ({
        "players/warlord/rooms/fut1", "south",
        "players/warlord/rooms/entrance", "north",
        });
}


