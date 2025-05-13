

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "road";
    long_desc = 
"\tThe path here looks very smooth and well traveled. The castle in\n\
front of you looks very impressive and very beautiful. As you look\n\
off into the distance you notice a dark shadow. You can see that\n\
the path continues north into the castle and to the east it leads\n\
to what looks and sounds like a bar. To the west you notice a hill\n\
which leads upwards to a small but elegant looking building.\n";
    dest_dir = 
        ({
              "players/warlord/rooms/room","north",
        "players/warlord/hill1", "west",
        "players/warlord/road1", "south",
        "players/warlord/wbar", "east",
        });
items=({
"castle","A large and white castle",
"tower","The tower looks black and evil",
"hill","You see a airly steep hill going up",
});
}


