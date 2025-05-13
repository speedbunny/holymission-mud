inherit "room/room";
reset(arg) {
if (arg) return;
set_light(3);
short_desc = "c25  E/W south hallway";
long_desc = "A long hallway inside the castle wall.\n"
+"The floor is made of red rocks, and the walls of grey stone.\n"
+ "There is a black carpet that runs the length of the hall.\n"
+"A small window in the south wall.\n";
items = ({
"floor", "A solid looking floor made of bright red stone",
"window","All you can see is lots of trees",
"carpet","A black carpet that runs the length of the hall",
"ceiling","It's made of white stone",
"wall","The walls are made of grey stone",
});
dest_dir = ({
"players/jake/goblin/castle/enter","east",
"players/jake/goblin/castle/c24","west",
});
}
