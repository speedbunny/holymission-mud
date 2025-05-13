inherit "/obj/thing";

#include "lw.h"
#include "/players/matt/defs.h"

status alldone;
int total, voted, abstain, vote_timer;
string topic, *choice_array, *voters, *hearers;
mixed *vote_array;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  topic = "";
  voters = allocate(0);
  hearers = allocate(0);
  vote_timer = 180;
  set_name("paper");
  set_alias("slip of paper");
  set_alt_name("poll");
  set_short("Slip of paper");
  set_long("This is a small slip of paper. Across the top are the words\n" +
	   "\"POLL-TAKER\". You can probably read it.\n");
  set_value(50);
  set_weight(0);
}

init() {
  ::init();
  add_action("read",     "read");
  add_action("issue",    "issue");
  add_action("choices",  "choices");
  add_action("timer",    "timer");
  add_action("send",     "send");
  add_action("percent",  "percent");
  add_action("announce", "announce");
  add_action("chuck",    "chuck");
}

read(arg) {
  if(id(arg)) {
    write("You read the slip of paper. It says:\n\n");
    write("This is a magical poll-taker. Commands:\n");
    write(" - issue:       Lets you write up the issue to be voted on\n");
    write(" - choices:     Lets you set the voting choices (optional)\n");
    write(" - timer <sec>: Gives voters <sec> seconds to vote.\n");
    write(" - send all:    Sends a ballot to every player\n");
    write(" - send <name>: Sends a ballot to <name>\n");
    write(" - percent:     Shows you the breakdown of votes\n");
    write(" - announce:    Announces the results of the vote (costs 1000)\n");
    write(" - chuck:       Destroys this paper\n\n");
    write("Enjoy!    - Matt\n");
    return 1;
  }
}

issue(arg) {
  if(!arg) {
    if(topic == "") {
      write("Write the issue to be voted on. When you're done, type **\n");
      write("on a line by itself.\n");
      write("--> ");
      input_to("write_issue");
      return 1;
    }
    write(lw(topic));
    return 1;
  }
}

write_issue(arg) {
  if(arg != "**") write("--> ");
  if(arg == "**") {
    if(topic != "")
      write("You finish writing your issue. To read it, type \"issue\".\n");
    else write("No issue written.\n");
    return 1;
  }
  topic += (arg + "\n");
  input_to("write_issue");
  return 1;
}

choices(arg) {
  int i;
  if(topic != "") {
    if(!arg) {
      if(!sizeof(choice_array)) {
	write("To enter the possible choices, type:\n");
	write("\"choices <choice1>//<choice2>,...\" etc. Make sure not to\n");
	write("put spaces next to the //. Example:\n");
	write("\"choices yes//no//maybe\".\n");
	return 1;
      }
      write("Choices are currently:\n");
      for(i = 0; i < sizeof(choice_array); i++)
	write("  #" + (i + 1) + " - " + choice_array[i] + "\n");
      return 1;
    }
    write("You set the choices. To see them, type \"choices\".\n");
    choice_array = explode(arg, "//");
    vote_array = allocate(0);
    for(i = 0; i < sizeof(choice_array); i++) {
      vote_array += ({ 0 });
      vote_array[i] = allocate(2);
      vote_array[i][0] = choice_array[i];
    }
    return 1;
  }
  write("You must first write an issue.\n");
  return 1;
}

timer(arg) {
  int time;
  if(sizeof(voters)) {
    write("Ballots have already been sent out.\n");
    return 1;
  }
  if(arg && sscanf(arg, "%d", time)) {
    if((time >= 30) && (time <= 300)) {
      write("You set the timer to " + time + " seconds.\n");
      vote_timer = time;
      return 1;
    }
    write("The time must be between 30 and 300 seconds.\n");
    return 1;
  }
}

send(arg) {
  int i;
  object *players, ballot, target;
  if(topic != "") {
    if(arg == "all") {
      players = filter_array(users(), "vote_filter", TO);
      for(i = 0; i < sizeof(players); i++) {
	ballot = clone_object(NWCITY + "objects/ballot");
	if(sizeof(choice_array)) ballot->set_choices(choice_array);
	if(!sizeof(voters)) call_out("do_dest", vote_timer);
	if(!sizeof(vote_array)) vote_array = allocate(0);
	ballot->set_topic(topic);
	ballot->set_sender(TP->RNAME, TO);
	MOVE(ballot, players[i]);
	total++;
	TELL(players[i], TP->SNAME + " sends you a ballot.\n");
	voters += ({ players[i]->RNAME });
      }
      write("You send a ballot to each player.\n");
      return 1;
    }
    if(arg) {
      target = find_player(arg);
      if(target) {
	if(!present("ballot", target) &&
	   (member_array(target->RNAME, voters) == -1)) {
	  if(!target->query_earmuff_level() &&
	     !target->queryenv("NO_BALLOT")) {
	    ballot = clone_object(NWCITY + "objects/ballot");
	    ballot->set_topic(topic);
	    ballot->set_sender(TP->RNAME, TO);
	    if(sizeof(choice_array)) ballot->set_choices(choice_array);
	    if(!sizeof(voters)) call_out("do_dest", vote_timer);
	    if(!sizeof(vote_array)) vote_array = allocate(0);
	    MOVE(ballot, target);
	    total++;
	    write("You send a ballot to " + target->NAME + ".\n");
	    TELL(target, TP->SNAME + " sends you a ballot.\n");
	    voters += ({ target->RNAME });
	    return 1;
	  }
	  write(target->SNAME + " is busy right now.\n");
	  return 1;
	}
	write(target->SNAME + " has already been sent a ballot.\n");
	return 1;
      }
      write("That person is not playing now.\n");
      return 1;
    }
    write("Send to whom?\n");
    return 1;
  }
  write("You must first write an issue.\n");
  return 1;
}

percent(arg) {
  int i;
  string correct;
  if(!arg) {
    if(topic != "") {
      if(sizeof(voters)) {
	write("Current percentages:\n");
	for(i = 0; i < sizeof(vote_array); i++) {
	  if(vote_array[i][1] == 1) correct = "vote";
	  else correct = "votes";
	  write(lw("  " + vote_array[i][0] + ": " +
		   (100 * vote_array[i][1] / total) +
		   "\% (" + vote_array[i][1] + " " + correct + ")\n"));
	}
	write("\nNumber of votes received:  " + voted + "\n");
	write("Number abstaining:         " + abstain + "\n");
	write("Number of ballots sent:    " + total + "\n");
	return 1;
      }
      write("You haven't sent out any ballots!\n");
      return 1;
    }
    write("You must first write an issue.\n");
    return 1;
  }
}

announce(arg) {
  int i;
  string correct, shout_str;
  if(!arg) {
    if(topic != "") {
      if(alldone) {
	if(TP->query_money() >= 1000) {
	  TP->add_money(- 1000);
	  shout_str = "";
	  write("You announce the results of the poll.\n");
	  write_file(LOGS + "polls",
		     "----- " + TP->SNAME + " on " + ctime(time()) + ".\n");
	  shout_str += TP->SNAME + " announces the results of " + TP->POS +
	    " poll.\n";
	  shout_str += "*Issue: " + topic;
	  for(i = 0; i < sizeof(vote_array); i++) {
	    if(vote_array[i][1] == 1) correct = "person";
	    else correct = "people";
	    shout_str += lw((100 * vote_array[i][1] / total) + "\% chose " +
	      vote_array[i][0] + " (" + vote_array[i][1] + " " +
	      correct + ")\n");
	  }
	  shout_str += "Number of votes received:  " + voted + "\n";
	  shout_str += "Number abstaining:         " + abstain + "\n";
	  shout_str += "Number of ballots sent:    " + total + "\n";
	  my_shout(shout_str);
	  drop();
	  return 1;
	}
	write("You need 500 coins to do that.\n");
	return 1;
      }
      write("Not everyone has voted yet.\n");
      return 1;
    }
    write("You must first write an issue.\n");
    return 1;
  }
}
      
chuck(arg) {
  int i;
  object *players, ballot;
  if(!arg || id(arg)) {
    write("You chuck the slip of paper. It disintegrates.\n");
    say(TP->SNAME + " chucks a slip of paper.\n");
    players = filter_array(users(), "ballot_filter", TO);
    for(i = 0; i < sizeof(players); i++) {
      ballot = present("ballot", players[i]);
      destruct(ballot);
      TELL(players[i], "Your ballot suddenly crumbles.\n");
    }
    destruct(TO);
    return 1;
  }
  write("Chuck what?\n");
  return 1;
}

drop() {
  int i;
  object ballot, *players;
  write("You drop the slip of paper. It disintegrates.\n");
  say(TP->SNAME + " drops a slip of paper, which disintegrates.\n");
  players = filter_array(users(), "ballot_filter", TO);
  for(i = 0; i < sizeof(players); i++) {
    ballot = present("ballot", players[i]);
    destruct(ballot);
    TELL(players[i], "Your ballot suddenly crumbles.\n");
  }
  destruct(TO);
  return 1;
}

do_dest() {
  int i;
  object ballot, *players;
  players = filter_array(users(), "ballot_filter", TO);
  for(i = 0; i < sizeof(players); i++) {
    ballot = present("ballot", players[i]);
    if(!ballot->query_vote()) set_vote();
    destruct(ballot);
    TELL(players[i], "The ballot disintegrates.\n");
  }
  if(total - (voted + abstain))
    for(i = 0; i < (total - (voted + abstain)); i++)
      set_vote();
  return 1;
}

my_shout(arg) {
  int i;
  object *players;
  players = filter_array(users(), "shout_filter", TO);
  for(i = 0; i < sizeof(players); i++)
    TELL(players[i], arg);
  write_file(LOGS + "polls", arg);
  return 1;
}

vote_filter(obj) {
  return !present("ballot", obj) && !obj->query_earmuff_level() &&
    (member_array(obj->RNAME, voters) == -1) &&
      !obj->queryenv("NO_BALLOT");
}

ballot_filter(obj) {
  return present("ballot", obj);
}

shout_filter(obj) {
  return (member_array(obj->RNAME, hearers) != -1) &&
    !obj->query_earmuff_level() && !obj->queryenv("NO_BALLOT");
}

add_hearer(arg) {
  hearers += ({ arg });
  return 1;
}

set_vote(arg) {
  int number, i;
  if(!arg) {
    abstain++;
    if((voted + abstain) == total) alldone = 1;
    return 1;
  }
  number = -1;
  for(i = 0; i < sizeof(vote_array); i++)
    if(vote_array[i][0] == arg) number = i;
  if(number != -1) {
    vote_array[number][1]++;
    voted++;
    if((voted + abstain) == total) alldone = 1;
    return 1;
  }
  number = sizeof(vote_array);
  vote_array += ({ 0 });
  vote_array[number] = allocate(2);
  vote_array[number][0] = arg;
  vote_array[number][1] = 1;
  voted++;
  if((voted + abstain) == total) alldone = 1;
  return 1;
}

query_time() { return find_call_out("do_dest"); }
