inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
string slash;
reset(arg){
if(arg) return 1;
slash="machete";
set_light(1);
short_desc="Base of a moutain";
long_desc=break_string(
	"The Jungle clears here revealing a huge moutain towering "+
	"above the jungle to the north. Vegetation covers the face "+
	"of the mountain almost to the top.\n",65);


items = ({
	"jungle", long_desc,
	"mountain","A huge mountain towering above this jungle",
	"vegetation","It is lush and green",
	"something","It already ran into the undergrowth",
	"face","The side of the mountain, covered in vegetation",
	"top","It is too far away, but you think you see a building",
	"inhabitants","You hear them no see them",
	});
property=({
	});
dest_dir=({
	IPATH+"jung121","north",
	IPATH+"jung110","west",
	IPATH+"jung112","east",
	IPATH+"jung101","southwest",
	});
}
void init(){
::init();
AA("_listen","listen");
AA("_cut","cut");
AA("_climb","throw");
AA("_north","north");
AA("_south","south");
AA("_west","west");
AA("_climb","climb");
}
_west(){
if(present(slash,TP)){
MOVE("hacking "+TPOSS+" way west#players/tatsuo/ishikawa/jungle/jung110");
return 1;
}
else
write("You don't have anything that could cut through the foliage.\n");
return 1;
}
_listen(){
write("You hear the cries of the jungle.\n");
return 1;
}
_north(){
if(present(slash,TP)){
MOVE("hacking "+TPOSS+" way north#players/tatsuo/ishikawa/jungle/jung121");
return 1;
}
else{
write("You don't have anything that could cut through the foliage.\n");
return 1;
}
}
_cut(){
write("If you have the right tool, you can just walk that way.\n");
return 1;
}
_south(){
write("You run into a mountain. OUCH!\n");
return 1;
}
_climb(){
write("You can't climb up here.\n");
return 1;
}
