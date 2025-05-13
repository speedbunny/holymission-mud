inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="In the arena.";
long_desc=
"You have come to the farthest northern part of the arena and it\n"+
"doesn't seem to be a happy place.  This is the area where they\n"+
"let all the slaves and animals into the arena when there isn't\n"+
"anyone in the immediate area.  Because you are here they cannot\n"+
"let any more in and so the crowd is booing you and dumping stuff\n"+
"over the walls on you.  You better leave here quick.\n";
dest_dir=({
        "players/bobo/arena/a11.c","south",
});
items=({
        "arena","Round in shape, the arena looks like it has high, unclimable walls",
        "slaves","Currently behind a gate in the wall the slaves seem to want you to stay",
        "animals","Behind a different gate the animals are being terrorized so they're mean",
        "crowd","Many vicious spectators awaiting bloodshed",
        "walls","The walls here are high and sheer and definitely unclimbable",
});
replace_program("room/room");
}
