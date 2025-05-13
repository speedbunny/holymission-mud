inherit "room/room";
reset (arg) {
if (arg) return;
set_light(3);
short_desc = "gob1";
long_desc = "A small dirt path.\n" 
+ "To the west you see what appears to be a village of some kind.\n";

items = ({"village","Why don't you go west and take a look for yourself?"}); 
dest_dir = ({
"players/jake/path","east",
"players/jake/goblin/gob2","west",
});
}
