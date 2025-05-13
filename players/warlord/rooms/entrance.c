

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "entrance";
    no_castle_flag = 0;
    long_desc = 
       "This is a large Entrance Hall. There are many pictures hanging here.\n"
      +"The only doors that are opened are to the north and south.\n";
    items = ({
          "pictures","The pictures depict battles all through time",
            });
    dest_dir = 
        ({
        "players/warlord/stone/time1", "north",
        "players/warlord/rooms/futent", "south",
        "players/warlord/hilltop", "leave",
/*
        "players/warlord/time3", "west",
        "players/warlord/time4", "east",
*/
"players/warlord/new/room1","in",
        });
}


