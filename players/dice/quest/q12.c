inherit "room/room";
object tr_hole;
string stone_desc;
status has_moved;
reset(arg) {
    if(arg){if(tr_hole) destruct(tr_hole);
	has_moved = 0; }

    stone_desc = "They have marks from movement";
    set_light(0);
    short_desc = "Cellar";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
    "The cellar under the house. The floor is covered with stones.\n"+
    "The walls seem solid. A staircase is leading up.\n";
    items = ({
      "cellar","A small cellar under the house",
      "walls","Solid walls, they are the foundation of the house",
      "wall","A solid wall, part of the foundation of the house",
      "floor","It's covered with big solid stones",
      "stones","@@query_stone_desc@@",
      "foundation","The stuff the house was built upon",
      "stairs","A small stairs leading up",
      "staircase","A small stairs leading up",
      "small stair","A small stair leading up",
    });

    smell = "The air smells dull here.";
}
init(){  
    ::init(); 
    add_action("move_stone","move");
    add_action("up","up"); add_action("up","u");
}
move_stone(str){
    if(!str){
	notify_fail("Move what ?\n");
	return 0;
    }
    if((str=="stone")||(str=="stones")){
	if(tr_hole){
	    write("You don't want to cover the hole again.\n"+
	      "It might be your only way out.\n");
	    return 1;
	}
	else{
	    write("With great effort you move the stones and discover a hole.\n");
	    tr_hole=clone_object("players/dice/quest/tr_hole.c");
	    move_object(tr_hole,this_object());
	    long_desc = "The cellar under the house.\n"+
	    "The floor is covered with stones. A small heap of stones is lying around. \n"+
	    "The walls seem solid. A small staircase is leading up.\n";
	    items += ({
	      "heap","A small heap of stones",
	      "small heap","A small heap of stones",
	    });
	    has_moved = 1;
	    return 1;
	}
    }
}
up(){
    write("You walk up the stairs.\n");
    this_player()->move_player("up the stairs#players/dice/quest/q11");
    return 1;
}
query_stone_desc(){
    if (has_moved){
	return "The stones are lying in this room after taking them from the ground";
    }
    else return stone_desc;}
