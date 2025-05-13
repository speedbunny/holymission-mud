inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="On a plain";
  long_desc="You are on a small plain. To the northeast the plain leads into a valley.\n"+
   "To the west lies a thick forest. The plain continues to the north.\n"+
   "A path leads south into some mountains.\n";

  dest_dir=({
	"players/bobo/krooms/mountains/plain2","north",
	"players/bobo/krooms/mountains/rocks11","south",
	"players/bobo/krooms/mountains/edge1","west",
	"players/bobo/krooms/mountains/valley4s","northeast",
	"players/bobo/krooms/mountains/rocks11","up",
   });
  
   items=({
     "forest","A thick forest with some very high trees",
     "valley","A valley between mountains",
   });
 
}
 
