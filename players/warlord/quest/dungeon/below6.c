inherit"players/warlord/NEWSTUFF/room";
reset(arg) {
if (arg) return;
set_light(0);
short_desc="Under the forest";
long_desc="This cavern is very wet. You can hear noises coming from the east.\n";
dest_dir=({
"/players/warlord/quest/dungeon/below4","up",
"/players/warlord/quest/dungeon/below7","east",
"/players/warlord/quest/dungeon/below9","down",
});
return 1;
}
