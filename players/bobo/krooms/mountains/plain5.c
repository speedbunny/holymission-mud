inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="On a plain";
  long_desc="You are on a small plain. It continues the the east and north.\n"+
   "To the south and west you can see a big forest\n";

  dest_dir=({
	"players/bobo/krooms/mountains/plain4","north",
	"players/bobo/krooms/mountains/edge1","south",
	"players/bobo/krooms/mountians/plain2","east",
	"players/bobo/krooms/mountains/edge3","west",
   });
  
   items=({
     "forest","A thick forest with some very high trees",
   });
 
}
 
