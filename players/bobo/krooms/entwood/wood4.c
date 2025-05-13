inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In a forest";
  long_desc="You are in a thick forest.\n"+
   "You don't see the exit anymore. You have a strange feeling here.\n"+ 
   "You think you can see trees changing their position. Maybe this forest\n"+
   "is enchanted.\n";

  dest_dir=({
	"players/bobo/krooms/entwood/wood3","south",
	"players/bobo/krooms/entwood/wood5","east",
	"players/bobo/krooms/entwood/wood11","west",
   });
  
   items=({
     "forest","A thick forest with some very high trees",
     "tree","You must have been dreaming, or maybe you got insane", 
     "trees","Well, because of all the trees you don't see the forest", 
   });
   if(!present("ent")) 
     move_object(clone_object("players/kelly/monster/ent"),this_object());
 
}
 
