reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("east");	     add_verb("east");
    add_action("southeast"); add_verb("southeast");
}

short()
{
    return "Focus Point";
}

id(str) { return str=="grove" || str=="pedestal"; }

long(str) {
  if(!str) {
    write("You are standing in a small grove on the western most point of the Isle\n" +
	  "of the Magi, Focus Point\n" +
	  "All of the trees here are either diseased, dead or heavily mutated.\n" +
	  "On the very end of the point stands an old, crumbling stone pedestal.\n" +
	  "Legend has it that Arcanarton mounted some sort of a magic focusing device\n"+
	  "here, and used the energy it collected to increase the power of his spells.\n" +
	  "The device is now nowhere to be found.\n" +
	  "The shore of the island continues east and southeast into a\n" +
	  "small grove from here\n" );
     return;
  }
  if(str=="pedestal") {
    write("A crumbling stone pedestal. On it are inscribed the words:\n"
	+ "Seek the windy icy wastes, and find the pattern therein,\n"
	+ "to find the portal to the lair of that evil creature.\n");
    return;
  }
  if(str=="grove") {
    write("A grove of diseased, dead or heavily mutated trees.\n");
    return;
  }
}

east()
{
    call_other(this_player(), "move_player", "east#room/south/sislnd11");
    return 1;
}

southeast()
{
     call_other(this_player(), "move_player", "southeast#room/south/sislnd9");
     return 1;
}
reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("east");	     add_verb("east");
    add_action("southeast"); add_verb("southeast");
}

short()
{
    return "Focus Point";
}

id(str) { return str=="grove" || str=="pedestal"; }

long(str) {
  if(!str) {
    write("You are standing in a small grove on the western most point of the Isle\n" +
	  "of the Magi, Focus Point\n" +
	  "All of the trees here are either diseased, dead or heavily mutated.\n" +
	  "On the very end of the point stands an old, crumbling stone pedestal.\n" +
	  "Legend has it that Arcanarton mounted some sort of a magic focusing device\n"+
	  "here, and used the energy it collected to increase the power of his spells.\n" +
	  "The device is now nowhere to be found.\n" +
	  "The shore of the island continues east and southeast into a\n" +
	  "small grove from here\n" );
     return;
  }
  if(str=="pedestal") {
    write("A crumbling stone pedestal. On it are inscribed the words:\n"
	+ "Seek the windy icy wastes, and find the pattern therein,\n"
	+ "to find the portal to the lair of that evil creature.\n");
    return;
  }
  if(str=="grove") {
    write("A grove of diseased, dead or heavily mutated trees.\n");
    return;
  }
}

east()
{
    call_other(this_player(), "move_player", "east#room/south/sislnd11");
    return 1;
}

southeast()
{
     call_other(this_player(), "move_player", "southeast#room/south/sislnd9");
     return 1;
}
