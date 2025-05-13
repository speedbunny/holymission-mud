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
	"above the jungle to the south. Vegetation covers the face "+
        "of the mountain almost to the top.  A path coming in from "+
	"the north continues up the mountain face to the south.\n.",65);


items = ({
	"jungle", long_desc,
	"path","It leads up the mountain",
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
	IPATH+"jung111","west",
	IPATH+"jung113","east",
	IPATH+"jung122","north",
	MPATH+"m2","up",
	});
}
void init(){
::init();
AA("_listen","listen");
AA("_cut","cut");
AA("_climb","throw");
AA("_south","south");
AA("_climb","climb");
}
_south(){
write("The path leads UP, the mountain to the south.\n");
return 1;
}
_listen(){
write("You hear the cries of the jungle.\n");
return 1;
}
_cut(){
write("If you have the right tool, you can just walk that way.\n");
return 1;
}
_north(){
write("You run into a mountain. OUCH!\n");
return 1;
}
_climb(){
write("You can't climb up here.\n");
return 1;
}
