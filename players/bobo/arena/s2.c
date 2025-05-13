inherit "room/room";
object peanuts;
reset (arg) {
if (arg) return;
clone_list=({
       1, 2, "slave","players/bobo/monsters/slave3", 0,
});
::reset(arg);
peanuts = clone_object("players/bobo/obj/peanuts.c");
transfer(peanuts,this_object());
peanuts = clone_object("players/bobo/obj/peanuts.c");
transfer(peanuts,this_object());
set_light(1);
short_desc="In the stands.";
long_desc=
"As you enter this area people scatter trying to get away from you\n"+
"pushing others and leaving trash and other things in their wake.\n"+
"The stands therefore are a wreck and are harder to navigate\n";
dest_dir=({
        "players/bobo/arena/s3.c","northeast",
        "players/bobo/arena/s1.c","southwest",
});
items=({
        "people","The people who seemed so loud and brave from the arena flee from you",
        "others","Smaller and slower people are being pushed out of the way",
        "trash","large piles of trash litter this area making it hard to move around",
        "stands","The stands are covered in refuse",
});
replace_program("room/room");
}
