inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Hallway.\n";
long_desc=
"This is a short hallway. To your north is the bathroom. To the\n"+
"south is the guest bedroom and to the west is Christian's study.\n";
dest_dir=({
"players/warlord/house/study","west",
"players/warlord/house/landing","east",
"players/warlord/house/guest_bed","south",
"players/warlord/house/bath","north",
});
}
