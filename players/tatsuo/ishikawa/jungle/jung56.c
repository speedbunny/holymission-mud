inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
object ob1;
string slash;
string southit;
string westit;
string hook;
reset(arg){
    if(arg) return 1;
    slash="machete";
    southit="jung42";
    westit="jung55";
    hook="grappling hook";
    set_light(1);
    short_desc="Base of a moutain";
    long_desc=break_string(
      "The Jungle clears here revealing a huge moutain towering "+
      "above the jungle to the north. Vegetation covers the face "+
      "of the mountain almost to the top.  A small patch of vegetation "+
      "appears to have burned off the side of the mountain some "+
      "distance up.\n",65);


    items = ({
      "jungle", long_desc,
      "patch","It looks as if something burned the side of the mountain.\n"+
      "you can't investigate from down here",
      "foliage","Thick intertwining vines restricting passage",
      "mountain","A huge mountain towering above this jungle. \n"+
      "You think you may be able to climb it with the right equipment",
      "vegetation","It is lush and green",
      "something","It already ran into the undergrowth",
      "face","The side of the mountain, covered in vegetation",
      "top","It is too far away, but you think you see a building",
      "inhabitants","You hear them no see them",
    });
    property=({ "no_teleport",
    });
    dest_dir=({
	IPATH+"jung42","south",
	IPATH+"jung57","east",
	IPATH+"jung55","west",
	IPATH+"jung70","northwest",
    });
}
void init(){
    ::init();
    AA("_listen","listen");
    AA("_cut","cut");
    AA("_climb","throw");
    AA("_climb","throw");
    AA("_north","north");
    AA("_west","west");
    AA("_south","south");
    AA("_climb","climb");
}
_listen(){
    write("You hear the cries of the jungle.\n");
    return 1;
}
_cut(){
    write("If you have the right tool, you can just walk that way.\n");
    return 1;
}
_south(){
    if(present(slash, TP)){
	MOVE("hacking "+TPOSS+" way south#players/tatsuo/ishikawa/jungle/"+southit);
	return 1;
    }
    else{
	write ("You don't have anything that could cut through the foliage.\n");
	return 1;
    }
}
_west(){
    if(present(slash, TP)){
	MOVE("hacking "+TPOSS+" way west#players/tatsuo/ishikawa/jungle/jung55");
	return 1;
    }
    else{
	write("You don't have anything that could cut through the foliage.\n");
	return 1;
    }
}
_climb(){
    int ctch, num;
    num=random(100)+1;
     if(num<TP->query_dex()) { ctch = 1; } else ctch = 0;
    if(!present(hook, TP)){
	write("You start to climb unaided, and fall....\n");
        TP->misc_hit(5);
	return 1;
    }
  else
	if(ctch) {
	    write("You throw the grappling hook up the mountain, and it catches!\n"+
	      "You climb up the face of the mountain.\n");
	    say(TPN+" throws a grappling hook up the face of the mountain. It catches!\n");
	MOVE("up the mountain#players/tatsuo/ishikawa/m1");
	    ctch=0;
	    return 1;
	}
       else {
	    write("You throw the grappling hook up the mountain and watch it tumble back down.\n");
	say(TPN+" throws a grappling hook up the mountain and watches it\n"+
	"tumble back down.\n");
	    return 1;
	}
}
_north(){
write("You run into a mountain!\n");
return 1;
}
