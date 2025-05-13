

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "hill";
    no_castle_flag = 0;
    long_desc = 
        "This part of the hill seems a little more smoother and easier footing.\n"
         + "The building at the top is a small castle.\n";
    dest_dir =
        ({
        "players/warlord/hill1", "down",
        "players/warlord/hilltop", "up",
        });
    items=({
        "hill","You see a lot of rocks",
        "building","It looks like a small castle",
        "castle","It is rather small but elegant",
           });
}

