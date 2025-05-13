inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc = "c17  North-west corner of castle";
long_desc = "The hall ends here.\n"
          + "The white carpet ends here, but a brown one extends south.\n"
          + "A hall extends south, and a small doorway in northwest corner.\n";
items = ({
"floor","It is made of red stone",
"ceiling","It is made of white stone",
"wall","It is made of grey stone, with a small window in it",
"window","You see out into a forest",
"carpet","A beautiful white carpet ends here, and a brown one picks up",
"doorway","A small doorway",
});
dest_dir = ({
"players/jake/goblin/castle/c16","east",
"players/jake/goblin/castle/c17a","northwest",
"players/jake/goblin/castle/c18","south",
});
}
