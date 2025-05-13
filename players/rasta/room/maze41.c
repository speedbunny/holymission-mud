/* 030795 Colossus: Updated to room.c */

#pragma strict_types;

inherit "room/room";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    short_desc = "Dry ganja field";
    long_desc =
    "You walk through a dry ganja field. The blazing sun has\n\
destroyed all the good sensimilia herb.\n";
    items = ({
      "field", "The field is full of ruined sensimilia herb",
      "herb", "The herb has been destroyed by the sun's heat",
      "sensimilia", "The herb has been destroyed by the sun's heat",
    });
    dest_dir = ({
      "/players/rasta/room/maze2", "north",
      "/room/void", "south",
      "/room/void", "west",
      "/room/void", "east",
    });
}

void init(){
    ::init();
    add_action("e0", "north");
    add_action("e1", "south");
    add_action("e2", "east");
    add_action("e3", "west");
}

status e0(){
    if(!random(2))
	this_player()->move_player("north#players/rasta/room/maze11");
    else
	this_player()->move_player("north#players/rasta/room/maze21");
    return 1;
}

status e1(){
    if(!random(2))
	this_player()->move_player("south#players/rasta/room/maze21");
    else
	this_player()->move_player("south#players/rasta/room/maze11");
    return 1;
}

status e2(){

    this_player()->move_player("east#players/rasta/room/quest_r1");
    return 1;
}
#if 0

if (!exit_num)
    call_other(this_player(), "move_player", "east#players/rasta/room/maze11");
else
    call_other(this_player(), "move_player", "east#players/rasta/room/quest_r1");
return 1;
}
#endif

status e3(){
    if(!random(2))
	this_player()->move_player("west#players/rasta/room/maze21");
    else
	this_player()->move_player("west#players/rasta/room/maze41");
    return 1;
}
