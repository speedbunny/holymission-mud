/* 12.13.93 Airborne: Changes to room/room and fixed up the format */

inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "The entrance to Darkwood. There is a sign here";
  long_desc = "You are standing in front of the entrance to darkwood.\n"+
	"you cannot see further than a few metres of the path\n"+
	"that is trailing into the forest.\n"+
	"There is a sign here.\n";
  items = ({ "sign", "An important looking sign",
	"path", "The path into darkwood",
	"forest", "The forest of Darkwood",
	"trees", "Lots of various trees in the forest",
	"tree", "One of many trees in the forest of Darkwood" });
   dest_dir = ({ "players/topaz/angmar/fairyland/dw_path1", "east",
		 "players/topaz/angmar/fairyland/path1", "west" });

}
init() {
  add_action("read", "read");
  ::init();
}
read(str) {
  if(str!="sign") return 0;
  readsign();
  return 1;
}

readsign() {
say(this_player()->query_name()+" reads the sign.\n");
write("Turn back stranger! You will find nothing\n");
write("but death in here! If you are a mighty\n");
write("warrior and think that you can free the\n");
write("town from the horrors in this forest we\n");
write("will be forever grateful to you, but\n");
write("remember that you have been warned!\n\n");

write("                         The Villagers\n");
}

