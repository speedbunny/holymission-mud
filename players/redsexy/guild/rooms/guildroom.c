// last edit: 16.03.99 redsexy - changed defs for temporary testing
// added something for the plaque 26.03.99

inherit "/guild/guild_room";
#include "/players/redsexy/guild/guilddefs.h"

string long_str;
object book;
object dude;

void reset(int arg) 
{
  ::reset(arg);
  if(!book) {
    book = clone_object(PATH + "objects/lorebook");
  move_object(book,this_object() );
  }
  if(!dude) {
   dude = clone_object("/players/redsexy/guild/creatures/aeternus");
  move_object(dude,this_object());
  }
  if(arg) return;
  short_desc = "Guild of Summoners";
  set_guild(SUMM);
  long_desc =
    "    This is the main room of the Guild of Summoners, dimly lit\n" +
    "by smokeless torches burning with an eery greenish flame. In\n" +
    "the northwest corner a staircase made of black stone spirals\n" +
    "up through the ceiling and down through the floor. A silver\n" +
    "plaque hangs on the wall, as well as a small sign.\n" +
    "    There is a doorway set into each of the west, north, east,\n" +
    "and south walls.\n";
    no_obvious_msg = "";
}

add_init() 
{
  add_action("read", "read");
  add_action("enter", "enter");
  add_action("up", "up");
  add_action("down", "down");
  add_action("west", "west");
  add_action("north", "north");
  add_action("east", "east");
  add_action("south", "south");
  add_action("climb", "climb");
  add_action("my_look", "look");
}

read(arg) {
  if(arg == "sign" || arg == "small sign") {
    write("You read the sign. It describes the standard guild commands.\n\n");
    write("  - join:       To join this Guild\n");
    write("  - advance:    Advances your level\n");
    write("  - list:       Lists your quest status\n");
    write("  - list all:   Gives a list of all current quests\n");
    write("  - list long:  Gives long descriptions of all quests\n");
    write("  - list <num>: Shows a description of given quest number\n");
    return 1;
  }

  if(arg == "plaque" || arg == "silver plaque") {
    write("You read the plaque. It has the basic standard of conduct on it:\n\n");
    write("Summoners are the most secretive of all guilds.\n");
    write("They have no allegiance to others and are even \n");
    write("untrusting of fellow Summoners until such a time\n");
    write("they have proven themselves to be worthy of that \n");
    write("respect. A Summoner can be banished from the guild\n");
    write("for many reasons, use your intelligence, play smart. \n");
       return 1;
  }


}

enter(arg) {
  if(arg == "door" || arg == "doorway") {
    write("Enter which doorway?\n");
    return 1;
  }
  else if(arg == "west doorway") west();
  else if(arg == "north doorway") north();
  else if(arg == "east doorway") east();
  else if(arg == "south doorway") south();
  else write("Enter what?\n");
  return 1;
}

up(arg) {
  if(!arg) climb("up");
  else return;
  return 1;
}

down(arg) {
  if(!arg) climb("down");
  else return;
  return 1;
}

west(arg) {
  int i, flag;
  object inv;
  if(!arg) {
    if((TP->query_guild() != SUMM) && !present("powertrial", TP) &&
       !present("watertrial", TP) && !TP->query_npc()) {
      if(!(PATH + "rooms/waterroom")->query_busy()) {
	write("You enter the Trial of Water.\n");
	TP->MOVEP("into the Trial of Water#" +
		  PATH + "rooms/waterroom");
	return 1;
      }
      write("Someone is already attempting the Trial of Water.\n");
      return 1;
    }
    write("You do not need to complete the Trial of Water.\n");
    return 1;
  }
}
north(arg) {
  int i, flag;
  object inv;
  if(!arg) {
    if((TP->query_guild() != SUMM) && !present("powertrial", TP) &&
       !present("windtrial", TP) && !TP->query_npc()) {
      if(!(PATH + "rooms/windroom")->query_busy()) {
	write("You enter the Trial of Wind.\n");
	TP->MOVEP("into the Trial of Wind#" +
		  PATH + "rooms/windroom");
	return 1;
      }
      write("Someone is already attempting the Trial of Wind.\n");
      return 1;
    }
    write("You do not need to complete the Trial of Wind.\n");
    return 1;
  }
}

east(arg) {
  int i, flag;
  object inv;
  if(!arg) {
    if((TP->query_guild() != SUMM) && !present("powertrial", TP) &&
       !present("earthtrial", TP) && !TP->query_npc()) {
      if(!(PATH + "rooms/earthroom")->query_busy()) {
	write("You enter the Trial of Earth.\n");
	TP->MOVEP("into the Trial of Earth#" +
		  PATH + "rooms/earthroom");
	return 1;
      }
      write("Someone is already attempting the Trial of Earth.\n");
      return 1;
    }
    write("You do not need to complete the Trial of Earth.\n");
    return 1;
  }
}

south(arg) {
  int i, flag;
  object inv;
  if(!arg) {
    if((TP->query_guild() != SUMM) && !present("powertrial", TP) &&
       !present("firetrial", TP) && !TP->query_npc()) {
      if(!(PATH + "rooms/fireroom")->query_busy()) {
	write("You enter the Trial of Fire.\n");
	TP->MOVEP("into the Trial of Fire#" +
		  PATH + "rooms/fireroom");
	return 1;
      }
      write("Someone is attempting the Trial of Fire.\n");
      return 1;
    }
    write("You do not need to complete the Trial of Fire.\n");
    return 1;
  }
}

climb(arg) {
  if(arg == "stairs" || arg == "staircase") {
    write("You can climb either up or down.\n");
    return 1;
  }
  if(arg == "up") {
    write("You climb up the staircase.\n");
    TP->MOVEP("up the staircase#" + PATH + "rooms/anteroom");
    return 1;
  }
  if(arg == "down") {
    if(TP->query_guild() == SUMM ||
       TP->query_immortal() || TP->query_npc()) {
      write("You climb down the staircase.\n");
      TP->MOVEP("down the staircase#" + PATH + "rooms/lounge");
      return 1;
    }
    write("Aeternus stops you.\n");
    write("Aeternus whispers: Only a true Summoner may pass.\n");
    return 1;
  }
  write("Climb what?\n");
  return 1;
}

my_look(arg) {
  switch(arg) {
      case "at stairs":
      write("A set of black stone stairs leading up and down.\n");
      return 1;
      break;
    case "at staircase":
      write("A set of black stone stairs leading up and down.\n");
      return 1;
      break;
    case "at corner":
      write("In the shadows stands a spiral staircase.\n");
      return 1;
      break;
    case "at northwest corner":
      write("In the shadows stands a spiral staircase.\n");
      return 1;
      break;
    case "at torches":
      write("Strange, magical torches.\n");
      return 1;
      break;
    case "at flame":
      write("An undying greenish flame, probably magical.\n");
      return 1;
      break;
    case "at ceiling":
      write("The ceiling, made of black stones.\n");
      return 1;
      break;
    case "at floor":
      write("The floor, made of black flagstones.\n");
      return 1;
      break;
    case "at wall":
      write("There are four walls, each with a doorway set into it.\n");
      return 1;
      break;
    case "at walls":
      write("There are four walls, each with a doorway set into it.\n");
      return 1;
      break;
    case "at doorway":
      write("There are four doorways.\n");
      return 1;
      break;
    case "at doorways":
      write("There are four doorways.\n");
      return 1;
      break;
    case "at west doorway":
      write("An inscription over the door reads 'Trial of Water'.\n");
      return 1;
      break;
    case "at north doorway":
      write("An inscription over the door reads 'Trial of Wind'.\n");
      return 1;
      break;
    case "at east doorway":
      write("An inscription over the door reads 'Trial of Earth'.\n");
      return 1;
      break;
    case "at south doorway":
      write("An inscription over the door reads 'Trial of Fire'.\n");
      return 1;
      break;
    case "at pedestal":
      write("A black stone pedestal supporting the large book.\n");
      return 1;
      break;
    case "at plaque":
      write("The plaque is in honor of Genocyber, who restored the Guild,\n");
      write("and Matt, the original Guild Master.  There is some writing \n");
      write("you could read...\n");
      return 1;
      break;
    case "at sign":
      write("A small sign on the wall. You could probably read it.\n");
      return 1;
      break;
  }
}

do_join() {
  int i;
  object power, players;
  if(::do_join()) return 1;
  if(!TP->query_gender()) {
    write("Aeternus whispers: Neuter characters may not join.\n");
    return 1;
  }
  power = present("powertrial", TP);
  if(power) {
    write("Aeternus whispers: You are ready, my child.\n");
    write("Congratulations. You are now a Summoner.\n");
    write("Aeternus whispers: Tell no one of what you have learned here.\n");
    write("Aeternus gives you a black cloak and a shard of the Prism.\n");
    say("Aeternus gives something to " + TP->SNAME + ".\n");
    say(TP->SNAME + " has joined the Guild.\n");
    log_file("GUILD.JOIN",
	       TP->SNAME + " joined at level " + TP->LEVEL + " on "
	       + ctime(time()) + ".\n");
    players = filter_array(users(), "guild_filter", TO);
    for(i = 0; i < sizeof(players); i++)
      TELL(players[i], TP->SNAME + " has become a Summoner.\n");
    TP->set_guild(SUMM);
    destruct(power);
    return 1;
  }
  write("Aeternus whispers: You must first demostrate your knowledge.\n");
  write("Aeternus whispers: To do this, you must take the Test.\n");
  return 1;
}

guild_filter(obj) { return obj->query_guild() == SUMM; }

query_room(arg) { if(arg == "long_desc") return long_str; }
query_property(arg) { return arg == "no_teleport"; }
query_maxsp(arg) { return (55 + 15 * (arg)); }
query_maxhp(arg) { return (arg * 20); }
