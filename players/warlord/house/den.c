inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Den.\n";
long_desc=
"This is the family den where they relax to watch TV or listen to music.\n";
dest_dir=({
"players/warlord/house/kitchen","east",
"players/warlord/house/deck","north",
});
}
