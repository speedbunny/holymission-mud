inherit "room/room";
reset (arg) {
if (arg) return;
clone_list=({
         1, 2, "slave","players/bobo/monsters/slave", 0,
});
::reset(arg);
set_light(1);
short_desc="Inside the arena.";
long_desc=
"You are in the south eastern most part of the arena.  The wall looms\n"+
"above you like a towering giant too large to see over into the stands\n"+
"near you.  This area seems relatively devoid of carnage compared to\n"+
"the rest of the arena. You can hear the crowd shouting for blood.\n";
dest_dir=({
        "players/bobo/arena/a8.c","north",
        "players/bobo/arena/a3.c","west",
});
items=({
        "arena","round in shape, the arena looks like it has high, unclimbable walls",
        "stands","Big stone steps double as seats for the crowds",
        "carnage","Though still great, it's not as bad as other parts in the arena",
});
replace_program("room/room");
}
