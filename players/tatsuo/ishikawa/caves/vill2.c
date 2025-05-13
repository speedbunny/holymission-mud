inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
reset(arg){
if(arg) return 1;
set_light(1);
short_desc="Village of Ishikawa";
long_desc=break_string(
      "You are following a path that leads through the village. It appears the "+
      "villagers are out at sea. Huts continue to run along the beach. There is "+
       "an interesting hut set atop poles with a ladder leading up to it. "+
      "The path continues north and south.\n",65);


items = ({
       "shore","The shore is lined with huts of the fishermen",
    "huts","The huts are circular in shape and are very small and made of wood",
    "wood","It appears to be bamboo with palm leaves covering the roof",
    "boats","There are several fishing boats on the sea",
    "sea","It is made of water FOOL!!!!",
    "poles","They support the huts and protect them from the tide and floods",
	"tide","It flows and ebbs over the black basaltic sand. You get dizzy",
	"sand","It is black, derived from a basaltic granite",
       "ladder","It leads to the entrance of the hut. Maybe you could climb it",
	});
property=({
	});
dest_dir=({
      CPATH+"vill3","north",
	CPATH+"vill1","south",
	IPATH+"jung76","west",
      
	});
}
void init(){
::init();
AA("_search","search");
AA("_climb","climb");
AA("_swim","swim");
}
_search(){
write("You search around for a while and find nothing.\n");
say(TPN+" searches around.\n");
return 1;
}
_swim(){
write("You jump in the ocean and swim around awhile.\n");
say(TPN+ " jumps in the ocean and swims around awhile.\n");
return 1;
}
_climb(str){
if(str=="ladder"){
MOVE("up the ladder#players/tatsuo/ishikawa/caves/hut2");
return 1;
}
if(!str){
write("You would look foolish climbing that!!!\n");
return 1;
}
}
