

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        " This rooms/hallway is pretty creepy. The walls almost seem to be staring \n"
        + "at you. Its is pretty dark in here. There are a lot of cobwebs around.\n";
items=({
"cobwebs","The cobwebs are large and elegant",
"walls","The walls look as if they have eyes",
});
    dest_dir = 
        ({
"players/warlord/drac/drachall1","north",
        "players/warlord/rooms/skel1","south",
"players/warlord/drac/drachall2","east",
        "players/warlord/rooms/hallway3", "portal",
        });
}

