inherit "room/room";
object nuts;
reset (arg) {
if (arg) return;
clone_list=({
        1, 3, "peasant","players/bobo/monsters/peasant3", 0,
        2, 2, "slave","players/bobo/monsters/slave2", 0,
});
::reset (arg);
nuts = clone_object("players/bobo/obj/peanuts.c");
transfer(nuts,this_object());
nuts = clone_object("players/bobo/obj/peanuts.c");
transfer(nuts,this_object());
set_light (1);
short_desc="In the stands.";
long_desc=
"You have come to an area below the balocny.  Looking up at\n"+
"the underside of it you can see a shiny opaque substance.  In\n"+
"the area immediately surrounding you there are cushions on top\n"+
"of the stone and there is surprisingly little trash here.\n";
dest_dir=({
        "players/bobo/arena/s8.c","northeast",
        "players/bobo/arena/s10.c","southwest",
});
items=({
        "balcony","You can only see the bottom of it, it's very shiny and dark",
        "substance","This strange dark stuff is unlike anything that you have ever seen",
        "area","This portion of the stands seems to be cleaner and more well kept",
        "cushions","Large soft cushions lay ontop of the hard stone surface",
        "trash","The commonplace trash is not so prevalent here",
        "stone","The majority of the stone is covered with think cushions",
});
replace_program("room/room");
}
