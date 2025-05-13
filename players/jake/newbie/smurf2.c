inherit "room/room";
reset (arg) {
if (arg) return;
set_light(3);
short_desc = "smurf2";
long_desc = "You are travelling down a cobblestone path in the smurf village.\n"
+  "There is a smurf house to your north, and what looks like a pool to the south.\n"
+  "It is very peaceful here.\n";
items = ({"path","A walkway made out of purple and grey stones\n"});
dest_dir =
({
"players/jake/newbie/gard7","west",
"players/jake/newbie/smurfhouse","north",
"players/jake/newbie/pool","south",
});
}
