int exit_num;

short() {
    return "Burning Desert";
}

long() {
    write("Burning Desert.\n");
    write("There are four obvious exits: north, south, west and east.\n");
}

reset() {
    exit_num = random(4);	/* "grin" */
    set_light(1);
}

init() {
    add_action("e0"); add_verb("north");
    add_action("e1"); add_verb("south");
    add_action("e2"); add_verb("east");
    add_action("e3"); add_verb("west");
}

e0() {
    if (exit_num == 0)
	call_other(this_player(),"move_player", "north#players/ted/hot/maze4");
    else
	call_other(this_player(),"move_player", "north#players/ted/hot/maze2");
    return 1;
}

e1() {
    if (exit_num == 1)
	call_other(this_player(),"move_player","south#players/ted/hot/maze2");
    else
	call_other(this_player(),"move_player","south#players/ted/hot/maze1");
    return 1;
}

e2() {
    if (exit_num == 2)
	call_other(this_player(),"move_player", "east#players/ted/hot/maze4");
    else
	call_other(this_player(),"move_player","east#players/ted/hot/maze3");
    return 1;
}

e3() {
    if (exit_num == 3)
	call_other(this_player(),"move_player", "west#players/ted/hot/maze3");
    else
	call_other(this_player(),"move_player", "west#players/ted/hot/maze4");
    return 1;
}
