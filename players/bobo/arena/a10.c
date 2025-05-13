inherit "room/room";
reset (arg) {
if (arg) return;
clone_list=({
        1, 1, "gladiator","players/bobo/monsters/gladiator4", 0,
        2, 1, "bear","players/bobo/monsters/gbear", 0,
});
::reset (arg);
set_light (1);
short_desc="In the arena.";
long_desc=
"You are at the north western edge of the arena.  This is an area\n"+
"that looks amazinly similar to the rest of the arena with its massive\n"+
"walls and death all over.  In fact you just stepped in something\n"+
"that looks like brains.\n";
dest_dir=({
        "players/bobo/arena/a11.c","east",
        "players/bobo/arena/a6.c","south",
});
items=({
        "arena","Round in shape, the arena looks like it has high, unclimbable walls",
        "walls","The wall is sheer and definitely unclimbable",
        "brains","You just stepped in a large pile of brains, they splattered all over your shoe",
});
replace_program("room/room");
}
