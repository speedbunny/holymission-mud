inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Balcony.\n";
long_desc=
"This is sturdy looking balcony. You can see the pool and deck from here.\n";
dest_dir=({
"players/warlord/house/master","south",
});
}
init() {
::init();
add_action("view","view");
}
