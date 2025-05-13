inherit "room/room";
#define MOVEP move_player
#define TP this_player()
reset (arg) {
   clone_list=({
      1, 1, "lizard","/players/bobo/monsters/clan/lizard", 0,
      });
   if (arg) return;
   ::reset (arg);
   set_light(1);
   short_desc="In a dense jungle.";
   long_desc=
	"You hack your way through the dense jungle to an area with less\n"+
        "foliage.  Decaying branches litter the ground here and there is\n"+
	"a small path leads north.  Following the path with you're eyes\n"+
	"you look to the north and see mammoth stone structures blotting\n"+
	"out the horizon.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/open/o2.c","north",
	"/players/bobo/clan/rooms/maze1/j26.c","south",
      });
   items=({
	"branches","Large leafy branches are scattered over the ground and kill the undergrowth",
	"foliage","The verdure isn't quite as thick here with little undergrowth visible",
	"ground","It is covered with dead branches, and there is a small path running along it",
	"horizon","You can't see much of the horizon through the jungle or the structures",
	"jungle","The jungle here is not as thickand you can easily orient yourself",
	"path","Apparently made by covering the ground with large leaves that kill undergrowth",
	"structures","Large ancient looking stone structures are visible to the north",
      });
}

status move(string arg) {
   string direction;
   if(!stringp(arg))
   arg = query_verb();
   if(arg!="south" && arg!="s")
   return ::move(arg);
   switch(random(3)) {
      case 0: direction = "maze1/j26"; break;
      case 1: direction = "maze2/J26"; break;
      case 2: direction = "maze3/j26"; break;
   }
   TP->MOVEP("leaves south#players/bobo/clan/rooms/" + direction);
   return 1;
}
