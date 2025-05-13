inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
string slash, eastit;
reset(arg){
    if(arg) return 1;
    slash="machete";
    eastit="jung119";
    set_light(1);
    short_desc="In the Jungles of Ishikawa";
    long_desc=break_string(
      "You find yourself at the "+
      "western edge "+
      "of a vast and dense jungle. Cries of the inhabitants of this "+
      "jungle can be heard all around you. Something scrurries past "+
      "your feet.  The Jungle becomes very dense to the east. You "+
      "may need something to cut through the jungle.  The coast can "+
      "be seen through the underbrush to the west.\n",65);


    items = ({
      "jungle", long_desc,
      "something","It already ran into the undergrowth",
      "coast","It lies to the west",
      "underbrush","It is very dense, but passable to the west",
      "inhabitants","You hear them no see them",
    });
    property=({
    });
    dest_dir=({
        IPATH+"beach28","west",
      IPATH+"jung3","east",
    });
}
void init(){
    ::init();
    AA("_listen","listen");
    AA("_cut","cut");
    AA("_east","east");
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
_listen(){
    write("You hear the cries of the jungle.\n");
    return 1;
}
_cut(){
    write("If you have the right tool, you can just walk that way.\n");
    return 1;
}
