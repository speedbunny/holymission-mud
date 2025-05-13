inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In a forest";
  long_desc="You are in a thick forest.\n"+
   "You're deep in the forest. You have a strange feeling here.\n"+ 
   "You think you can see trees changing their position. Maybe this forest\n"+
   "is enchanted. To the west you can see a high wall.\n";

  dest_dir=({
	"players/bobo/krooms/entwood/wood7","south",
	"players/bobo/krooms/entwood/wood9","east",
   });
  
   items=({
     "forest","A thick forest with some very high trees",
     "tree","You must have been dreaming, or maybe you got insane", 
     "trees","Well, because of all the trees you don't see the forest", 
     "wall","A wall made of perfectly fitting stones",
   });
 
}
 
init() {
::init();
  add_action("climb","climb");
}

climb(str) {
  if(str!="wall") return;
  write("You try hard, but you fail to reach the top.\n");
  say(this_player()->query_name()+"tries to climb up the wall, but fails.\n");
  return 1;
}
