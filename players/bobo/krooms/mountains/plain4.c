inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="On a plain";
  long_desc="You are on a small plain.\n"+
   "To the west you can see a big forest\n";

  dest_dir=({
	"players/bobo/krooms/mountians/plain5","south",
	"players/bobo/krooms/mountains/plain1","east",
	"players/bobo/krooms/mountains/edge4","west",
   });
  
   items=({
     "forest","A thick forest with some very high trees",
   });
 
}
 
