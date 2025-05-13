inherit "room/room";
reset(arg) {
if (arg) return;
set_light(3);
short_desc = "North corner room...c9";
long_desc =
 "The northeastern corner of the castle.\n"
+ "The blue carpet ends here, but a white one leads west.\n"
+ "A small window in the north and east walls.\n";
items = ({
"floor","It's made out of ruby-red stone",
"wall","They are made out of grey stones",
"ceiling","It's made of pearl-white stone",
"window","You see a big forest which surrounds the castle",
"carpet","A lovely blue carpet which is partially covered by a beautiful white carpet",
}); 
dest_dir = ({
 "players/jake/goblin/castle/c8","south",
"players/jake/goblin/castle/c10","west",
"players/jake/goblin/castle/c9a","northeast",
});
}
