inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
reset(arg){
if(arg) return 1;
set_light(1);
short_desc="Village of Ishikawa";
long_desc=break_string(
      "You are standing below a hut that is larger than the rest of the huts in the "+
      "village. It appears to be decorated extravagantly with shields and spears "+
      "used to decorate it. The sea is east of the village. There are poles "+
      "supporting the hut, and there is a ladder leading to the entrance of the hut. "+
      "The path continues farther to the north.\n",65);


items = ({
       "shore","The shore is lined with huts of the fishermen",
    "huts","The huts are circular in shape and are very small and made of wood",
    "wood","It appears to be bamboo with palm leaves covering the roof",
    "boats","There are several fishing boats on the sea",
    "sea","It is made of water FOOL!!!!",
    "shields","The shields are covered with intricate designs",
	"hut","A large hut, decorated with weapons",
    "designs","They are oriental in nature",
    "spears","They appear to be very sharp",
    "poles","They support the huts and protect them from the tide and floods",
	"horizen","The horizen glows red with the setting sun",
	"tide","It flows and ebbs over the black basaltic sand. You get dizzy",
	"sand","It is black, derived from a basaltic granite",
       "ladder","It leads to the entrance of the hut. Maybe you could climb it",
	});
property=({
	});
dest_dir=({
	CPATH+"vill5","northwest",
	CPATH+"vill3","south",
	IPATH+"jung96","west",
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
MOVE("up the ladder#players/tatsuo/ishikawa/caves/hut4");
return 1;
}
else if (!str){
write("You would look really foolish climbing that!!!\n");
return 1;
}
}
