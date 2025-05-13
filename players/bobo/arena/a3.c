inherit "room/room";
reset (arg) {
if (arg) return;
clone_list=({
         1, 2, "lion","players/bobo/monsters/lion", 0,
});
::reset(arg);
set_light(1);
short_desc="Inside the arena.";
long_desc=
"You are not quite at the center of the large arena.  There is\n"+
"a lot of carnage around here, dead animals and people lie\n"+
"askew everywhere you look.  From this point you can see nearly\n"+
"everything going on both in the stands and around you.  You\n"+
"can also just make out a balcony in the stands northwest of you.\n";
dest_dir=({
        "players/bobo/arena/a7.c","north",
        "players/bobo/arena/a4.c","east",
        "players/bobo/arena/a1.c","south",
        "players/bobo/arena/a2.c","west",
});
items=({
        "arena","Round in shape, the arena looks like it has high, unclimbable walls",
        "carnage","Bones and blood from various animals or people are all over the area",
        "animals","Dead animals killed defending themselves",
        "people","slave and gladiator alike lie in piles in the arena",
        "stands","Big stone steps double as seats for the crowds",
        "balcony","You can just make out two figures sitting in the box watching over everything",
});
replace_program("room/room");
}
