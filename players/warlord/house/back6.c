inherit"room/room";
reset(arg) {
::reset(arg);
if(arg) return;
set_light(1);
short_desc="Back yard.\n";
long_desc=
"You are in the backyard of the house.\n";
dest_dir=({
"players/warlord/house/back5","west",
"players/warlord/house/back7","south",
});
}
