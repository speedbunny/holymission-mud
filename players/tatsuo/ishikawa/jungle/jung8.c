inherit "room/room";
#include "/players/tatsuo/def.h"
#define DIR ({"jung14","jung4","jung9","jung7"})
#include "/players/tatsuo/break_string.h"
string slash, northit, southit, eastit, westit;
object ob, ob2, ob3;
reset(arg){
    if(arg) return 1;
    slash="machete";
    northit= DIR[0];
    southit= DIR[1];
    eastit=  DIR[2];
    westit=  DIR[3];
    set_light(0);
    ob=CO("/players/tatsuo/ishikawa/chatters/jungchat");
    MO(ob,this_object());
    short_desc="In the Jungles of Ishikawa";
    long_desc=break_string(
      "You find yourself in a dark and very dense jungle. The "+
      "treetops form a canopy, blocking all sunlight. The jungle "+
      "is so dense that it is difficult, if not impossible, to move "+
      "through it without a machete. You have an eerie feeling that many "+
      "eyes are watching you. Several creatures scurry through the "+
      "undergrowth. Be afraid, Be very afraid.\n",65);


    items = ({
      "jungle", long_desc,
      "sunlight","You can't see it, the canopy blocks it out",
      "canopy","A natural canopy formed by the intertwined treetops",
      "eyes","You can see them, you feel them",
      "undergrowth","A plethora of green things",
      "something","It already ran into the undergrowth",
      "treetops","They form the canopy of the jungle",
      "creatures","You can't see them",

      "inhabitants","You hear them not see them",
    });
    property=({
      "no_teleport"
    });
    dest_dir=({
      IPATH+northit, "north",
      IPATH+southit, "south",
      IPATH+eastit, "east",
      IPATH+westit, "west",
    });
}
void init(){
    ::init();
    AA("_listen","listen");
    AA("_cut","cut");
    AA("_cut","hack");
    AA("_west","west");
    AA("_east","east");
    AA("_north","north");
    AA("_south","south");
    AA("_climb","climb");
    AA("_enter","enter");
}
_west(){
    if(present(slash,TP)){
	MOVE("hacking "+TPOSS+" way west#players/tatsuo/ishikawa/jungle/"+westit);
	return 1;
    }
    else
	write("You don't have anything that could cut through the foliage.\n");
    return 1;
}
_east(){
    if(present(slash,TP)){
	MOVE("hacking "+TPOSS+" way east#players/tatsuo/ishikawa/jungle/"+eastit);
	return 1;
    }
    else
	write("You don't have anything that could cut through the foliage.\n");
    return 1;
}
_north(){
    if(present(slash,TP)){
	MOVE("hacking "+TPOSS+" way north#players/tatsuo/ishikawa/jungle/"+northit);
	return 1;
    }
    else
	write("You don't have anything that could cut through the foliage.\n");
    return 1;
}
_south(){
    if(present(slash,TP)){
	MOVE("hacking "+TPOSS+" way south#players/tatsuo/ishikawa/jungle/"+southit);
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
_cut(){
    write("If you have the right tool, you can just walk that way.\n");
    return 1;
}
_climb(str){
    if(!str){
	write("Climb what?\n");
	return 1;
    }
    else {
	if(str=="tree"){
	    write("You start to climb up the tree...\n");
	    write("You almost reach the treetops...\n");
	    write("Suddenly a monkey drops a coconut on your head!");
	    write("You fall...\n");
	    write("THUD\n");
	    TP->misc_hit(15,2,0);
	    ob2=CO("/players/tatsuo/ishikawa/obj/coconut");
	    MO(ob2, this_object());
	    return 1;
	}
	else{
	    write("You can't climb that.\n");
	    return 1;
	}
    }
}
_enter(){
    return 1;
}
