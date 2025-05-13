inherit "room/room";
reset (arg) {
if (arg) return;
clone_list=({
        1, 1, "lion","players/bobo/monsters/lion", 0,
        2, 1, "tiger","players/bobo/monsters/tiger", 0,
        3, 1, "bear","players/bobo/monsters/bear", 0,
});
::reset (arg);
set_light (1);
short_desc="In the arena.";
long_desc=
"You are directly north of the center of the arena and feel as though\n"+
"you are in deep trouble.  Looking around this area you don't see\n"+
"anything out of the ordinary, the stands are still there, the people\n"+
"in them are still screaming, the arena still looks like it's in\n"+
"chaos, but then you look up to the balcony and see the two people\n"+
"on it are staring directly at you with a fixed gaze and shivers\n"+
"run down your spine.\n";
dest_dir=({
        "players/bobo/arena/a13.c","north",
        "players/bobo/arena/a12.c","east",
        "players/bobo/arena/a7.c","south",
        "players/bobo/arena/a10.c","west",
});
items=({
        "arena","Round in shape, the arena looks like it has high, unclimbable walls",
        "stands","Big stone steps double as seats for the crowds",
        "crowds","Screaming at combatants it seems some have picked their favorites",
        "balcony","High above anything else this offers an ideal look out point",
        "people","Their eyes are cold, hard, and staring right at you, you shiver with fear",
});
replace_program("room/room");
}
