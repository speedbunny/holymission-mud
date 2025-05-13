inherit "room/room";
reset (arg) {
if (arg) return;
set_light(3);
short_desc = "gob3";
long_desc = "A cobblestone path running east-west through the village.\n"
+  "You hear grunting noises coming from the north.\n"
+ "It smells really nasty here.\n";
items = 
({
"path","A path made of multi-colored rocks",
});
dest_dir = 
({"players/jake/goblin/gob2","east",
"players/jake/goblin/gob4","west",
"players/jake/goblin/hut3","south",
"players/jake/goblin/hut","north",
});
}
