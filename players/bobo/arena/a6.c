inherit "room/room";
reset (arg) {
if (arg) return;
clone_list=({
         1, 1, "gladiator","players/bobo/monsters/gladiator1", 0,
         2, 1, "tom","players/bobo/monsters/gladiator2", 0,
});
::reset(arg);
set_light(1);
short_desc="Inside the arena.";
long_desc=
"You are near the center of the arena and all around you meyhem\n"+
"seems to have broken out, there are many battles going on and\n"+
"the crowd seems to be going wild!  You are deafened by their\n"+
"shouting.  Looking at the stands you can see a few faces here\n"+
"and there.  In the north western part of the stands you can\n"+
"see a balcony that seems to have two people in it.\n";
dest_dir=({
        "players/bobo/arena/a10.c","north",
        "players/bobo/arena/a7.c","east",
        "players/bobo/arena/a2.c","south",
        "players/bobo/arena/a5.c","west",
});
items=({
        "arena","Round in shape, the arena looks like it has high, unclimbable walls",
        "meyhem","Utter and complete chaos has broken out all around you",
        "battles","Many people are fighting with eachother as well as with animals",
        "crowd","The crowd is going wild seeing the blood that they came here for",
        "stands","big stone steps double as seats for the crowds",
        "faces","Mad looking people both chanting and screaming at combatants",
        "balcony","You can see pretty clearly that there are two people on it watching over",
        "people","Though you cannot see their faces they appear important from thier dress",
});
replace_program("room/room");
}
