inherit "room/room";
#include "/players/unuscione/def.h"
#include "/players/unuscione/break_string.h"
reset(arg){
 if(arg) return;
set_light(0);
short_desc="Dungeon of Hilo";
long_desc=break_string(
	"The smell of wet dog becomes stronger to the west.  You "+
	"are in a very small corridor that turns here.  The sound of water can be heard from above. Maybe a "+
	"waterfall cascading into a pool on the surface.\n",65);
smell="It really smells like wet dog here";
items=({"corridor",long_desc,
	"ceiling","It looks stable",
	"surface","You are on the wrong side of the ground",
        "waterfall","You hear it, not see it",
	});
dest_dir=({KPATH+"room7","north",
	   KPATH+"room12","west",
	});
}
init(){
  ::init();
  AA("_north","north");
  AA("_west","west");
}
_north(){
  if(TP->query_size()>2){
  write("You appear to have become lodged in this tunnel.\n");
  return 1;
  }
  else{
 MOVE("north#players/unuscione/area/room7");
  return 1;
  }
}
_west(){
  if(TP->query_size()>2){
  write("You appear to have become lodged in this tunnel.\n");
  return 1;
 }
 else{
  MOVE("west#players/unuscione/area/room12");
 return 1;
}
}
