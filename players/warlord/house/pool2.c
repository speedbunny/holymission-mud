inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Deep end of pool.\n";
long_desc=
"You are in the deep end of the pool. The shallow end is just a few \n"+
"feet away. There is also a diving board here.\n";
dest_dir=({
"players/warlord/house/board","board",
"players/warlord/house/pool1","shallow",
});
}
