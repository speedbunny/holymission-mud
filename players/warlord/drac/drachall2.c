

inherit "room/room";
object o1,o2,o3;

reset(arg) {
    if (arg) return;

    set_light(3);
    short_desc = "Undead hallway\n";
    long_desc = 
        "This hallway is well lit, but yet you still feel like you're being watched.\n"
        + "There is a lot of commotion coming from the east.\n";
    dest_dir = 
        ({
"players/warlord/rooms/grimroom","east",
        "players/warlord/drac/drac1","west",
        });
}

