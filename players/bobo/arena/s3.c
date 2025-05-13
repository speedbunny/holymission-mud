inherit "room/room";
object nuts;
reset (arg) {
if (arg) return;
clone_list=({
        1, 1, "peasant","players/bobo/monsters/peasant", 0,
        2, 1, "slave","players/bobo/monsters/slave3", 0,
});
::reset(arg);
nuts = clone_object("players/bobo/obj/peanuts.c");
transfer(nuts,this_object());
set_light (1);
short_desc="In the stands.";
long_desc=
"You are in the stands of the collesium.  Looking down at the arena you\n"+
"can see vicious battles all over.  looking around here it appears that\n"+
"the stands are just steps large enough to sit on and they go up quite\n"+
"high.  At the top there appears to be a large wall so that people can't\n"+
"jump off and commit suicide off of it.\n";
dest_dir=({
        "players/bobo/arena/s4.c","northeast",
        "players/bobo/arena/s2.c","southwest",
});
items=({
        "stands","Large steps double as seats for the now vacant crowds",
        "arena","Round in shape, it looks like the arena has high, unclimbable walls",
        "battles","People and animal alike fighting to the death",
        "wall","A large wall keeping the crowds from killing themselves after lost bets",
});
replace_program("room/room");
}
