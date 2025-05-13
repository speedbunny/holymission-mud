inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="A path";
  long_desc="You are walking along a small path leading northeastwards into the countryside\n"
	+ "and a range of mountains, and southwards into the village and Sun Alley.\n";
  dest_dir=({ "players/moonchild/trollslayer/patha", "northeast",
	"room/sunalley2", "south", });
  items=({ "path", "A small, winding country path",
	"mountains", "A tall range of mountains to the distant north",
	"countryside", "The countryside seems rather devoid of animals around here" });
}
