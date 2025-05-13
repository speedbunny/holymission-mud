int exit_num;

short() {
    return "A dry ganja field";
}

long() {
    write("You walk through a dry ganja field.\n"+
    "The blazing sun has destroyed all of the good sensimilia herb.\n");
    write("There are four obvious exits: north, south, west and east.\n");
}


reset() {
    exit_num = random(2);   
}

init() {
    add_action("e0"); add_verb("north");
    add_action("e1"); add_verb("south");
    add_action("e2"); add_verb("east");
    add_action("e3"); add_verb("west");
}

e0() {
    if (!exit_num)
	call_other(this_player(), "move_player", "north#players/rasta/room/maze11");
    else
	call_other(this_player(), "move_player", "north#players/rasta/room/maze21");
    return 1;
}

e1() {
    if (!exit_num)
	call_other(this_player(), "move_player", "south#players/rasta/room/maze21");
    else
	call_other(this_player(), "move_player", "south#players/rasta/room/maze11");
    return 1;
}

e2() {

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

e3() {
    if (!exit_num)
	call_other(this_player(), "move_player", "west#players/rasta/room/maze21");
    else
	call_other(this_player(), "move_player", "west#players/rasta/room/maze41");
    return 1;
}
