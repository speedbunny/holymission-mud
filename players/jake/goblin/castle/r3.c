inherit "room/room";
reset (arg) {
if (arg) return;
set_light(2);
short_desc = "hall to armoury";
long_desc =
   "You are in some sort of an entry-way.\n"
 +  "There is nothing in this room, except for a small picture on the wall.\n";
items = ({
"floor","The floor is made of red stone",
"ceiling","It is made of white stone",
"wall","The walls are made of grey stone",
"picture","A small picture of a majestic looking goblin",
});
dest_dir = ({
 "players/jake/goblin/castle/h3","west",
 "players/jake/goblin/castle/r5","south",
 "players/jake/goblin/castle/r4","east",
});
}
