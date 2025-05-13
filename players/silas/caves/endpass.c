inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "End of Passage";
    no_castle_flag = 0;
    long_desc = 
        "The passage ends here in a large room which has been hewn out of the rock.\n"
        + "Ashes on the ground betray the presence of earlier visitors, as do the\n"
        + "footprints here. For a reason you can't quite trace you feel eerie in this\n"
        + "room and feel the urge to leave quickly.\n";
    items = ({
         "footprints","They all lead to the center of the room and vanish",
         "ashes","Remainders of a large bonfire",
            });
    dest_dir = 
        ({
        "/players/silas/caves/pass6", "south",
        });
     smell = "The faint smell of incense mixes in with the cave's moldy smell.\n";
}

query_light() {
    return 0;
}
