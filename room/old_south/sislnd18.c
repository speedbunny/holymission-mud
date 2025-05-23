reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("north"); add_verb("north");
    add_action("south"); add_verb("south");
    add_action("east");  add_verb("east");
    add_action("west");  add_verb("west");
}

short()
{
    return "The ruins of Arcanarton's tower";
}

long()
{
    write("You are standing among the ruins of the tower of the evil mage, Arcanarton.\n" +
	  "Legend has it that the tower was destroyed in the mage wars about five hundred\n" +
	  "years ago, when all of the mages of Lustria combined their forces and attacked\n" +
	  "Arcanarton. A great many of them were killed, but they succeeded in destroying\n" +
	  "the evil mage's tower. His Body was never found, and rumours still abound\n" +
	  "that Arcanarton had become a Lich and has come back to haunt this isle.\n" +
	  "The powerful aura of magical combat still hangs in the air here.\n" +
	  "Lumps of half melted rock lay strewn about, and there is very little of\n" +
          "the original structure left standing.\n" +
	  "\nTo the north of the ruins, the hill slopes down to the bridge to the mainland.\n" +
	  "To the east stands a crumbling monument. To the west, an old, disused well.\n" +
	  "To the south of the ruins, the hill slopes away, down to the edge of Crescent Lake.\n");
}

north()
{
    call_other(this_player(), "move_player", "north#room/south/sislnd13");
    return 1;
}

south()
{
    call_other(this_player(), "move_player", "north#room/south/sislnd16");
    return 1;
}

east()
{
    call_other(this_player(), "move_player", "north#room/south/sislnd15");
    return 1;
}

west()
{
    call_other(this_player(), "move_player", "west#room/south/sislnd17");
    return 1;
}
reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("north"); add_verb("north");
    add_action("south"); add_verb("south");
    add_action("east");  add_verb("east");
    add_action("west");  add_verb("west");
}

short()
{
    return "The ruins of Arcanarton's tower";
}

long()
{
    write("You are standing among the ruins of the tower of the evil mage, Arcanarton.\n" +
	  "Legend has it that the tower was destroyed in the mage wars about five hundred\n" +
	  "years ago, when all of the mages of Lustria combined their forces and attacked\n" +
	  "Arcanarton. A great many of them were killed, but they succeeded in destroying\n" +
	  "the evil mage's tower. His Body was never found, and rumours still abound\n" +
	  "that Arcanarton had become a Lich and has come back to haunt this isle.\n" +
	  "The powerful aura of magical combat still hangs in the air here.\n" +
	  "Lumps of half melted rock lay strewn about, and there is very little of\n" +
          "the original structure left standing.\n" +
	  "\nTo the north of the ruins, the hill slopes down to the bridge to the mainland.\n" +
	  "To the east stands a crumbling monument. To the west, an old, disused well.\n" +
	  "To the south of the ruins, the hill slopes away, down to the edge of Crescent Lake.\n");
}

north()
{
    call_other(this_player(), "move_player", "north#room/south/sislnd13");
    return 1;
}

south()
{
    call_other(this_player(), "move_player", "north#room/south/sislnd16");
    return 1;
}

east()
{
    call_other(this_player(), "move_player", "north#room/south/sislnd15");
    return 1;
}

west()
{
    call_other(this_player(), "move_player", "west#room/south/sislnd17");
    return 1;
}
