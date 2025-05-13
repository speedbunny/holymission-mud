inherit "room/room";
object corpses;
reset (arg) {
if (arg) return;
clone_list=({
        1, 1, "gladiator","players/bobo/monsters/gladiator3", 0,
        2, 1, "lion","players/bobo/monsters/lion", 0,
});
::reset (arg);
corpses = clone_object("players/bobo/obj/corpses.c");
transfer(corpses,this_object());
set_light(1);
short_desc="In the arena.";
long_desc=
"You are directly east of the center of the arena, you have to step\n"+
"around rotting corpses to make it through this area.  Amidst all\n"+
"this you can't seem to escape the crowd yelling at you from the\n"+
"stands or the people in the balcony to the north west.\n";
dest_dir=({
        "players/bobo/arena/a12.c","north",
        "players/bobo/arena/a9.c","east",
        "players/bobo/arena/a4.c","south",
        "players/bobo/arena/a7.c","west",
});
items=({
        "arena","Round in shape, the arena looks like it has high, unclimbable walls",
        "crowd","Ranting and raving at the sight of blood",
        "stands","Big stone steps double as seats for the crowds",
        "balcony","You can barely make it out in the distance but there are two people on it",
        "people","You can't see them real well but you know that they're there",
});
replace_program("room/room");
}
