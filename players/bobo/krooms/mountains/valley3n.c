inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In a valley";
  long_desc="You're in a valley in the mountains.\n"+
   "To the east the valley get closer.\n";
  dest_dir=({
c
	"players/bobo/krooms/mountains/valley3s","south",
	"players/bobo/krooms/mountains/valley4n","west",
	"players/bobo/krooms/mountains/valley2","southeast",
   });
}
 
