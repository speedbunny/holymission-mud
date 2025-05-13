

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "hill";
    long_desc = 
        "This is a fairly steep hill but there are enough rocks around where its\n"
        + "climbable. You can see a sort of building at the top.\n";
items=({
"building","It looks like a small castle from here",
"rocks","The rocks are small and make for easy footing",
"hill","The hill is rocky",
});
    dest_dir = 
        ({
        "players/warlord/road2", "east",
        "players/waldo/area/room/l11", "west",
        "players/warlord/hill2", "up",
        });
}

