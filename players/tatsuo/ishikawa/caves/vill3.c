inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
reset(arg){
if(arg) return 1;
::reset(arg);
set_light(1);
short_desc="Village of Ishikawa";
long_desc=break_string(
        "You are following a path running down the shoreline. There are patches of "+
        "huts running in a straight line along the shore. The is a group of huts to "+
        "the south and what appears to be a larger hut to the north. "+
        "The path continues north and south.\n",65);


items = ({
       "shore","The shore is lined with huts of the fishermen",
    "huts","The huts are circular in shape and are very small and made of wood",
    "wood","It appears to be bamboo with palm leaves covering the roof",
    "boats","There are several fishing boats on the sea",
    "sea","It is made of water FOOL!!!!",
       "horizon","The horizon glows red with the setting sun",
	"tide","It flows and ebbs over the black basaltic sand. You get dizzy",
	"sand","It is black, derived from a basaltic granite",
	});
property=({
	});
dest_dir=({
     CPATH+"vill4","north",
	CPATH+"vill2","south",
	IPATH+"jung86","west",
      
	});
}
void init(){
::init();
AA("_search","search");
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
