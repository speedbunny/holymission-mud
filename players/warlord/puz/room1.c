inherit "room/room";
int             i, j, l;
reset(arg)
{
    ::reset(arg);
    if (arg)
	return;
    j = 21;
    l = 0;
    set_light(1);
    short_desc = "Puzzle room #1\n";
    long_desc =
	"You are in a puzzle room. This room is for the puzzle called NIM.\n" +
	"This puzzle consists of 21 O's, where you play against the room.\n" +
	"The object is to take away 1- 3 O's until you force the room to \n" +
	"take the last O. Don't you be the one to take the last O.\n" +
	"Type try puzzle to start.\n";
    dest_dir = ({
	});
}
init()
{
    ::init();
    add_action("try", "try");
    add_action("check", "check");
    add_action("remove", "remove");
}
try(str)
{
    if (l != 1) {
	if ((str == "the puzzle") || (str == "puzzle")) {
	    call_out("flip", 1);
	    return 1;
	} else {
	    write("You want to try what?\n");
	    return 1;
	}
    } else {
	write("The room needs time to think now. Come back later.\n");
	return 1;
    }
}
do_puzzle()
{
    for (i = 0; i < j; i++) {
	write("O ");
    }
    write("\n");
    return 1;
}
remove(var)
{
    int             k, l;
    sscanf(var, "%d", l);
    if ((l < 1) || (l > 3)) {
	write("You can only pick from 1-3 O's\n");
	return 1;
    }
    if (j < l) {
	write("You can't take " + l + " there are only " + j + " O's left.\n");
	return 1;
    }
    j -= l;
    if (j <= 0) {
	call_out("you_lose", 0);
	return 1;
    }
    write("You removed " + l + " O's\n");
    k = 4 - l;
    write("The room removes " + k + " O's\n");
    j -= k;
    call_out("do_puzzle", 1);
    if (j <= 0) {
	call_out("you_win", 0);
	return 1;
    }
    return 1;
}
wait()
{
    return 1;
}
you_win()
{
    write("You win!!\n");
    l = 1;
    this_player()->add_exp(10000);
    return 1;
}
you_lose()
{
    write("You lose.\n");
    l = 1;
    return 1;
}
check()
{
    call_out("do_puzzle", 0);
    return 1;
}

flip()
{
    write("I'll flip a coin. Heads you go first. Tails I go first.\n");
    call_out("wait", 5);
    write("The room flips a coin high into the air.\n");
    call_out("wait", 5);
    if (!random(2)) {
	write("It lands heads. You go first. You can remove 1-3 O's.\n");
	return 1;
    } else {
	write("It lands tails. The room will start.\n");
	call_out("room_start", 0);
    }
}
room_start()
{
    int             k;
    k = (random(3));
    j -= k;
    call_out("do_puzzle", 0);
}
