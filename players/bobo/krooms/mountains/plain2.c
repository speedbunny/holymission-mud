inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="On a plain";
  long_desc="You are on a small plain. To the east the plain leads into a valley.\n"+
   "To the west the plain continues and far in the west you can see a big forest\n";

  dest_dir=({
	"players/bobo/krooms/mountains/plain1","north",
	"players/bobo/krooms/mountains/plain3","south",
	"players/bobo/krooms/mountains/plain5","west",
	"players/bobo/krooms/mountains/valley4n","northeast",
	"players/bobo/krooms/mountains/valley4s","southeast",
   });
  
   items=({
     "forest","A thick forest with some very high trees",
     "valley","A valley between mountains",
   });
 
}
 
