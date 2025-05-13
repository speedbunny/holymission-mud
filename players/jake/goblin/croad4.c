inherit "room/room";
reset (arg) {
if (arg) return;
set_light(3);
short_desc = "croad4";
long_desc = "A path towards the mighty Goblin Castle.\n"
+ "The path is well worn, as if travelled a lot.\n" 
+ "You can barely make out the top of the castle over the trees.\n";
items = ({
"trees","Large evergreen trees",
"path","A very worn dirt path",
"castle","You can just see the tips of the castle towers.\nThey are bright red.",
});
dest_dir = ({
"players/jake/goblin/croad3","west",
"players/jake/goblin/croad5","north",
});
}
