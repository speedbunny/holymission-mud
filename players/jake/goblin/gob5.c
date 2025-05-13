inherit "room/room";
reset (arg) {
if (arg) return;
set_light(3);
short_desc = "gob5";
long_desc = "The path splits here.  To the north you see a strange castle.\n"
+"To the south the path continues.\n";
items = ({
"castle","Way off in the distance you see a castle",
});
dest_dir = ({ 
"players/jake/goblin/gob4","east",
"players/jake/goblin/gob6","south",
"players/jake/goblin/croad","north",
});
}
