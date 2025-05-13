inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
reset(arg){
if(arg) return 1;
set_light(1);
short_desc="Village of Ishikawa";
long_desc=break_string(
        "You are on a path leading through the middle of a tiny village. "+
        "This appears to be a fishing village.  Several boats have been pulled up onto the shore. "+
        "The huts look like single room buildings made of wood and palm leaves. "+
"They are sitting atop poles that are buried in the ground. There are ladders "+
        "leading up to the entrances of the huts. "+
	"The coastline continues to the southwest and north. "+
	"The sun is setting over a dark jungle to the west. "+
        "The path continues to the north further into the village.\n",65);


items = ({
       "shore","The shore is lined with huts of the fishermen",
	"boat","There are several fishing boats on the beach",
	"ladders","A ladder leads up into a hut. Maybe you could climb it",
    "huts","The huts are circular in shape and are very small and made of wood",
	"hut","The huts are circular in shape and are made of wood",
	"boats","There are several fishing boats on the beach",
    "sea","It is made of water FOOL!!!!",
    "poles","They support the huts and protect them from the tide and floods",
	"horizon","The horizon glows red with the setting sun",
	"tide","It flows and ebbs over the black basaltic sand. You get dizzy",
	"sand","It is black, derived from a basaltic granite",
       "ladder","It leads to the entrance of the hut. Maybe you could climb it",
        "sun","ARGH! you burn your retina",
	});
property=({
	});
dest_dir=({
      CPATH+"vill2","north",
      
	IPATH+"beach15","southwest",
	IPATH+"jung64","west",
	});
}
void init(){
::init();
AA("_search","search");
AA("_climb","climb");
AA("_swim","swim");
AA("_enter","enter");
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
MOVE("up the ladder#players/tatsuo/ishikawa/caves/hut1");
return 1;
}
else if (!str){
write("You would look foolish climbing that!!!\n");
return 1;
}
}
_enter(str){
if (str=="boat" || str=="boats"){
write("These small fishing boats would be very dangerous to take out to sea.\n");
write("You might want to search for a more seaworthy vessel.\n");
return 1;
}
else if (str=="hut"){
write("Why not just climb the ladder.\n");
return 1;
}
else
{
write("Enter what?\n");
return 1;
}
}
