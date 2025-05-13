inherit "room/room";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Bottom of tree";
    long_desc =
    "You are at the bottom of the Tree of Time and Space. The tree towers\n"+
    "high above you and emits an aura of magic. The tree itself has a golden\n"+
    "brown bark and silver leaves. You've never seen a more beautiful tree\n"+
    "than this. There is a ladder for you to climb up the tree.\n";

    dest_dir = ({
      "room/wild1", "south",
      /*
	    "/players/colossus/knights/knight_store", "rift",
      */
      "players/colossus/mearth/tree2", "up",
    });

    items = ({
      "tree", "The Tree of Time and Space",
      /*
	    "rift", "A rift in the fabric of the space time continuum",
      */
      "ladder", "A ladder for you to get up the tree",
      "bark", "A golden brown bark",
      "leaves", "Silver leaves",
    });
}
void init(){
    ::init();
    add_action("climb", "climb");
}

int climb(string str){
    if(str!="tree" || str!="up") return 0;
    else {
	this_player()->move_player("up#/players/colossus/mearth/tree2");
	return 1;
    }
}
