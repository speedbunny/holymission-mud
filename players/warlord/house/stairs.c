inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Stairs.\n";
long_desc="Main staircase leading to landing upstairs and foyer downstairs.\n"+
"On the east wall you see a picture hanging up.\n";
items=({
"picture","Its a picture of the lovely couple on there honeymoon",
});
dest_dir=({
"players/warlord/house/foyer","down",
"players/warlord/house/landing","up"
});
}
