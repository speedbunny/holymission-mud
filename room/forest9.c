inherit "room/room";

void reset(int arg) {

    ::reset(arg);

    if(!arg) {
        short_desc="Deep forest";

        long_desc=
                  "You are in a forest. The path leads east and " +
                  "south from here.\n";

        set_light(1);

        "players/cashimor/objects/sandmass"->short();

        dest_dir=({
                   "room/forest2","east",
                   "room/forest3", "south",
                 });

        items=({"forest","Everything looks dark green",
                "building","It seems solid and closed"});
    }
}

