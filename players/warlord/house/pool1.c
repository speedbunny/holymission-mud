inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Shallow end of pool.\n";
long_desc=
"You are in the shallow end of the pool. The deep end is just a few \n"+
"feet away. There is also a diving board there.\n";
dest_dir=({
"players/warlord/house/deck","deck",
"players/warlord/house/board","board",
"players/warlord/house/pool2","deep",
});
}
