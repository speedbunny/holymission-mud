inherit "room/room";
object obj;
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="Village entrance";
long_desc=
"Welcome to Red Rock Junction!  All around in this area is a red sort of\n"+
"clay.  The road leading southwest seems to be old and needs repairing\n"+
"while the road to the north is fabulously well maintained.  There is a\n"+
"sign next to the road.\n";
    dest_dir=({
    "players/kelly/rooms/vill/road1","north",
    "players/kelly/rooms/vill/eastroad7","southwest",
   });
   items=({
   "sign","It's a wooden sign. Perhaps you should read it",
   "road","It is made of excellent fitting stones. It seems to be a rich village",
   });
}
init() {
::init();
  add_action("read","read");
}
status read(string str) {
  if (str!="sign") return 0;
  write("It reads: WELCOME TO RED ROCK JUNCTION.\n"+
        "          The town with the best police\n"+
	"	   the best pub, the best inn AND\n"+
	"	   the best armory every seen.\n");
  return 1;
}
