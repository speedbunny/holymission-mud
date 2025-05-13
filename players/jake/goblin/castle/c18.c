inherit "room/room";
reset (arg) {
if (arg) return;
set_light(3);
short_desc = "c18  N/S hallway  west";
long_desc =  
"The hall extends north and south.\n"
+"The carpet extends off into the distance.\n"
+"There is a small window in the western wall.\n"; 
items = ({
"floor","It is made of red stone",
"ceiling","It is made of pearl white stone",
"wall","It is made of grey stone",
"window","You see a big forest full of trees",
"carpet","A brown carpet",
});
dest_dir = ({
"players/jake/goblin/castle/c17","north",
"players/jake/goblin/castle/c19","south",
});
}
