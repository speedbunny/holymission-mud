

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "road";
    long_desc = 
"\tThis is a beautiful path leading to a wonderous castle. You can\n\
see trees off in the distance and beautiful flowers all around. You\n\
feel like the owner here is a majestic soul. You can even hear birds\n\
happily singing. Off to the east and west are two small huts and the\n\
path continues to the north and south.\n";
    items = ({
   "trees","The trees are very sparce and thin",
    "flowers","The flowers are bright and colorful",
    "birds","The birds are robins",
    "hut","The hut is made of straw",
    "huts","The huts are made of straw",
            });
    dest_dir = 
        ({
        "players/warlord/road2", "north",
        "players/warlord/trans/port1","up",
        "players/warlord/hut1", "east",
        "players/warlord/hut2", "west",
        "room/mount_top", "south",
        });
}
