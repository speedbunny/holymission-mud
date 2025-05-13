inherit "/room/room";

object obj;

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="Village entrance";
   long_desc=
	"Welcome to Red Rock Junction!  All around in this area is a red "+
	"sort of clay.  The road leading southwest seems to be old and needs "+
	"repairing while the road to the north is fabulously well maintained."+
	"  There is a sign next to the road.\n";
   dest_dir=({
	"/players/bobo/krooms/vill/road1","north",
	"/players/bobo/krooms/vill/eastroad7","southwest",
   });
   items=({
	"sign","It's a wooden sign.  Perhaps you should read it",
	"road","It's made of excellent fitting stones.  It seems to be a "+
	       "rich village",
   });
}

init() {
   ::init();
   add_action("read","read");
}
status read(string str) {
   if (str!="sign") return 0;
   write("It reads: WELCOME TO RED ROCK JUNCTION.\n"+
         "          The town with the best police,\n"+
         "          the best pub, the best inn AND\n"+
	 "          the best armory ever seen.\n");
   return 1;
}
