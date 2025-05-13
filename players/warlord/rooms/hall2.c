inherit"room/room";
reset (arg) {
    if (arg) return;
    set_light(1);
    short_desc="Short Corridor\n";
    long_desc="You walked into a dim lit intersection. To the East and West are\n"+
    "arches.\n";
    items=({
      "arches","There are two of them one to the west and one to the east",
      "west arch","This arch has eloquent designs on it and a sign above it",
      "east arch","This arch is heavily damaged",
      "sign","The sign is old and tattered, but still is readable",
    });
    dest_dir=({
      "players/warlord/rooms/hounroom","south",
"players/warlord/drac/a1","east",
      "players/warlord/drac/gravent","west",
    });
}
init() {
    ::init();
    add_action("read","read");
}
read(str) {
    if (str=="the sign" || str=="sign") {
	write("To the west is the graveyard. Do not go there. No one returns.\n");
	return 1;
    }
}
