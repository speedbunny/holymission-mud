

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(2);
    short_desc = "hallway";
    no_castle_flag = 0;
    long_desc = 
        "This is a well lit hallway. You feel a strange presence around.\n"
        + "Its almost like someone is watching you. There is a shimmering \n"
        + "portal in front of you and a large Oak arch south of you.\n";
    dest_dir = 
        ({
        "players/warlord/drac/drac1", "portal",
        "players/warlord/rooms/throneroom", "south",
        "players/warlord/rooms/hallway2", "west",
        });
     items=({
      "portal","The portal is a shimmering white blur, breeching the east",
      "arch","An oak arch",
        });
}

