inherit"players/warlord/NEWSTUFF/room";
reset(arg) {
if (arg) return;
set_light(0);
short_desc="Burrowed room";
long_desc="This room looks as if it was made by something eating its way \n"+ 
          "through. You hear a noise from the west. It sounds like \n"+
          "something burrowing.\n";
dest_dir=({
"/players/warlord/quest/dungeon/below7","west",
"/players/warlord/quest/dungeon/below5","up",
});
}
