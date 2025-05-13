inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
string slash, westit;
reset(arg){
    if(arg) return 1;
    slash="machete";
westit="jung3";
    set_light(1);
    short_desc="In the Jungles of Ishikawa";
    long_desc=break_string(
      "You find yourself at the "+
      "eastern edge "+
      "of a vast and dense jungle. Cries of the inhabitants of this "+
      "jungle can be heard all around you. Something scrurries past "+
      "your feet.  The jungle becomes very dense to the west. You "+
      "may need something to cut through the jungle.  The coast can "+
      "be seen through the underbrush to the east.\n",65);


    items = ({
      "jungle", long_desc,
      "something","It already ran into the undergrowth",
      "inhabitants","You hear them no see them",
      "undergrowth","A plethora of green things",
      "underbrush","It is very dense but passable to the east",
      "coast","It lies to the east",
    });
    property=({
    });
    dest_dir=({
      IPATH+"beach5","east",
      IPATH+"jung3","west",
    });
}
void init(){
    ::init();
    AA("_listen","listen");
    AA("_cut","cut");
    AA("_west","west");
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
_listen(){
    write("You hear the cries of the jungle.\n");
    return 1;
}
_cut(){
    write("If you have the right tool, you can just walk that way.\n");
    return 1;
}
