int exit_num;
short() {
    return "Dry ganja field";
}

long() {
    write("You walk through a dry ganja field.\n"+
    "The blazing sun has destroyed all of the good sensimilia herb.\n");
    write("There are four obvious exits: north, south, west and east.\n");
}

reset() {
    exit_num = random(3);     
}

init() {
    add_action("exit1"); add_verb("north");
    add_action("exit2"); add_verb("south");
    add_action("exit3"); add_verb("east");
    add_action("exit4"); add_verb("west");
}

exit1() {
    if (!random(3))
	call_other(this_player(), "move_player", 
	  "north#players/rasta/room/maze31");
    else
	call_other(this_player(), "move_player", 
	    "north#players/rasta/room/maze21");
    return 1;
}

exit2() {
    if (!random(3))
	call_other(this_player(), "move_player", 
	  "south#players/rasta/room/maze21");
    else          
	call_other(this_player(), "move_player", 
	    "south#players/rasta/room/maze31");
    return 1;
}

exit3() {
    if (!random(3))
	call_other(this_player(), "move_player", 
	 "east#players/rasta/room/maze31");
    else
	call_other(this_player(), "move_player", 
	"east#players/rasta/room/maze21");
    return 1;
}

exit4() {
    if (!random(3))
	call_other(this_player(), "move_player", 
	  "west#players/rasta/room/maze21");
    else
	call_other(this_player(), "move_player", 
	 "west#players/rasta/room/ground1");
    return 1;
}

