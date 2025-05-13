inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In a forest";
  long_desc="You are in a thick forest.\n"+
   "You're deep in the forest.You have a strange feeling here.\n"+ 
   "You think you can see trees changing their position. Maybe this forest\n"+
   "is enchanted. To the west you can see a high wall.\n";

  dest_dir=({
	"players/bobo/krooms/entwood/wood8","north",
	"players/bobo/krooms/entwood/wood6","east",
   });
  
   items=({
     "forest","A thick forest with some very high trees",
     "tree","You must have been dreaming, or maybe you got insane", 
     "trees","Well, because of all the trees you don't see the forest", 
     "wall","A wall made of perfectly fitting stones",
   });
 
}
 
