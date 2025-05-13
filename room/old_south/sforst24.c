reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("south"); add_verb("south");
    add_action("east");  add_verb("east");
    add_action("west");  add_verb("west");
}

short()
{
    return "A dimly lit forest";
}

long()
{
    write("You are in part of a dimly lit forest - the trees are all around you.\n" +
	"Trails lead south and east, and a narrow path leads off to the west.\n" +
	"    There are three obvious exits: east, south and west.\n");
}

south()
{
    call_other(this_player(), "move_player", "south#room/south/sforst25");
    return 1;
}

east()
{
    call_other(this_player(), "move_player", "east#room/south/sforst23");
    return 1;
}

west()
{
    this_player()->move_player("west#players/whisky/quest/room/ravine1");
    return 1;
}
reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("south"); add_verb("south");
    add_action("east");  add_verb("east");
    add_action("west");  add_verb("west");
}

short()
{
    return "A dimly lit forest";
}

long()
{
    write("You are in part of a dimly lit forest - the trees are all around you.\n" +
	"Trails lead south and east, and a narrow path leads off to the west.\n" +
	"    There are three obvious exits: east, south and west.\n");
}

south()
{
    call_other(this_player(), "move_player", "south#room/south/sforst25");
    return 1;
}

east()
{
    call_other(this_player(), "move_player", "east#room/south/sforst23");
    return 1;
}

west()
{
    this_player()->move_player("west#players/whisky/quest/room/ravine1");
    return 1;
}
