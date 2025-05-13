inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In a forest";
  long_desc="You are in a thick forest.\n"+
   "You can leave it to the east. You have a strange feeling here.\n"+ 
   "You think you can see trees changing their position. Maybe this forest\n"+
   "is enchanted. To the south a path leads into the mountains.\n";

  dest_dir=({
	"players/bobo/krooms/entwood/wood2","north",
	"players/bobo/krooms/mountains/path15","south",
	"players/bobo/krooms/entwood/edge2","east",
	"players/bobo/krooms/entwood/wood6","west",
   });
  
   items=({
     "forest","A thick forest with some very high trees",
     "tree","You must have been dreaming, or maybe you got insane", 
     "trees","Well, because of all the trees you don't see the forest", 
   });
 
}
 
