inherit"/players/warlord/NEWSTUFF/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Bottom of tree trunk.\n";
long_desc="You are in the bottom of the tree trunk. It looks rotted.\n"
         +"You can see light below you.\n";
items=({
"tree trunk","The tree trunk is rotting and decaying.",
      });
dest_dir=({
"/players/warlord/quest/dungeon/below1","up",
"/players/warlord/quest/dungeon/below3","down",
 });
return 1;
}
