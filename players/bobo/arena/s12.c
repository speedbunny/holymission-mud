inherit "room/room";
object nuts;
reset (arg) {
if (arg) return;
clone_list=({
        1, 1, "father","players/bobo/monsters/father", 0,
        2, 2, "peasant","players/bobo/monsters/peasant3", 0,
        3, 2, "slave","players/bobo/monsters/slave4", 0,
});
::reset (arg);
nuts = clone_object("players/bobo/obj/peanuts.c");
transfer(nuts,this_object());
nuts = clone_object("players/bobo/obj/peanuts.c");
transfer(nuts,this_object());
set_light (1);
short_desc="In the stands.";
long_desc=
"This area looks basically the same as the rest of the collesium,\n"+
"void of people, and full of garbage.  The only thing that is out\n"+
"of the ordinary here is the fact that there seems to be a little\n"+
"search party looking for a lost boy while staying away from you\n"+
"at the same time.\n";
dest_dir=({
        "players/bobo/arena/s1.c","southeast",
        "players/bobo/arena/s11.c","northwest",
});
items=({
        "colliseum","A large stone structure housing an arena",
        "people","All the people are gone, except a small search party",
        "garbage","the usual refuse is in this area",
        "search party","A small group of people looking for a boy and avoiding you",
        "party","A small group of people looking for a boyu and avoiding you",
});
replace_program("room/room");
}
