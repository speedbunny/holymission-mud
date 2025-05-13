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
	"players/bobo/krooms/entwood/wood1","east",
	"players/bobo/krooms/entwood/wood7","west",
   });
  
   items=({
     "forest","A thick forest with some very high trees",
     "tree","You must have been dreaming, or maybe you got insane", 
     "trees","Well, because of all the trees you don't see the forest", 
   });
   if(!present("huorn"))  
     move_object(clone_object("players/bobo/kmonster/huorn"),this_object());
 
}
 
