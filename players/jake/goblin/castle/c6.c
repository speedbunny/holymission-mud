inherit "room/room";
reset (arg) {
if (arg) return;
set_light(3);
short_desc = "c6...empty hall";
long_desc =  
"The hall extends north and south.\n"
+"The carpet extends off into the distance.\n"
+"There is a small window in the eastern wall.\n";
items = ({
"floor","It is made of red stone",
"ceiling","It is made of pearl white stone",
"wall","It is made of grey stone",
"window","You see a beautiful horizon far off to the east",
"carpet","A bright blue carpet extending off into the north",
});
dest_dir = ({
"players/jake/goblin/castle/c7","north",
"players/jake/goblin/castle/c5","south",
});
}
