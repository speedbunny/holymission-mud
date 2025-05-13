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
    add_action("exit1", "north");
    add_action("exit2", "south");
    add_action("exit3", "east");
    add_action("exit4", "west");
}

status exit1(){
    if (!random(3))
	this_player()->move_player("north#players/rasta/room/maze31");
    else
	this_player()->move_player("north#players/rasta/room/maze21");
    return 1;
}

status exit2(){
    if (!random(3))
	this_player()->move_player("south#players/rasta/room/maze21");
    else          
	this_player()->move_player("south#players/rasta/room/maze31");
    return 1;
}

status exit3(){
    if (!random(3))
	this_player()->move_player("east#players/rasta/room/maze31");
    else
	this_player()->move_player("east#players/rasta/room/maze21");
    return 1;
}

status exit4(){
    if (!random(3))
	this_player()->move_player("west#players/rasta/room/maze21");
    else
	this_player()->move_player("west#players/rasta/room/ground1");
    return 1;
}

