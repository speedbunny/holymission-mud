#include "/players/tamina/defs.h"

int exit_num;

string short() 
{
    return "Burning Desert";
}

void long() 
{
    write("Burning Desert.\n");
    write("There are four obvious exits: north, south, west and east.\n");
}

void reset() 
{
    exit_num = random(4);	/* "grin" */
    set_light(1);
}

void init() 
{
    add_action("e0", "north");
    add_action("e1", "south");
    add_action("e2", "east");
    add_action("e3", "west");
}

int e0() 
{
    if (exit_num == 0)
	MPL("north#/players/tamina/teds/hot/maze3");
    else
	MPL("north#/players/tamina/teds/hot/maze4");
    return 1;
}

int e1() 
{
    if (exit_num == 1)
	MPL("south#/players/tamina/teds/hot/maze4");
    else
	MPL("south#/players/tamina/teds/hot/maze1");
    return 1;
}

int e2() 
{
    if (exit_num == 2)
	MPL("east#/players/tamina/teds/hot/maze3");
    else
	MPL("east#/players/tamina/teds/hot/maze4");
    return 1;
}

int e3() 
{
    if (exit_num == 3)
	call_other(this_player(),"move_player","west#/players/tamina/teds/hot/maze4");
    else
	MPL("west#/players/tamina/teds/hot/maze2");
    return 1;
}
