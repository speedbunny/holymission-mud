inherit "room/room";
reset (arg) {
if (arg) return;
set_light(3);
short_desc = "In smurf village";
long_desc = "You are still travelling down the cobblestone path in the smurf village.\n"
+ "You can see some small mushroom houses to the north.\n"
+  "A small tree has grown up ther[D[Drough the path here.\n";
items = ({"path","A walkway made out of purple and grey stones\n",
  "tree","A small tree.  It does not look climable\n",
  "cobblestone","See 'path'\n"});
dest_dir =
({
"players/jake/newbie/smurf2","west",
"players/jake/newbie/patha","north",
});
}
