inherit"room/room";
reset(arg) {
::reset(arg);
if(arg) return;
set_light(1);
short_desc="Path.\n";
long_desc=
"This is a path that leads from the backyard to the lake.\n";
dest_dir=({
"players/warlord/house/path2","north",
"players/warlord/house/back5","south",
});
}
