inherit"players/warlord/NEWSTUFF/room";
reset(arg) {
if (arg) return;
set_light(0);
short_desc="cavern";
long_desc="This cavern is very cold. You see a glimpse of something\n"+
          "on the wall.\n";
items=({
"wall","You see carvings scratched into the wall",
"carvings","You try very hard to decifer the carvings it looks like they\n"+
           "say:..The horn will help......\n",
});
dest_dir=({
"/players/warlord/quest/dungeon/below6","up",
});
}
