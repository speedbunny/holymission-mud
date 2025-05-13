
/* estate_agent.c       Metaprat     6th April 1992  */

#include "/players/silas/houses/house_defines.h"

object key;
int revenue_so_far;


id(str) {
    return (str == "agent")  ||  (str == "estate agent");
}


short() {
    return "An estate agent, with a thick folder full of properties";
}


long() {
    string name;
    name = this_player()->query_real_name();
    write("This individual is a typical estate agent, with little regard\n");
    write("for the truth.  Not that he tells lies, but 360 degree bending\n");
    write("of the few hard facts is normal practice as far as he is\n");
    write("concerned.\n");
    if (has_got_key()) {
	write("You notice that the agent is looking with a disgusted\n");
	write("expression at your house key, muttering something about\n");
	write("you already owning enough property.\n");
	return 1;
    }
    else if(file_size(sprintf(HOUSES_DIR + "%c" + "/" +
	  "%s" + ".o", name[0], name)) > 0 ) {
	/* in case the autoloading key didn't get autoloaded. */
	key = clone_object(HOUSEKEY);
	/*  log_file(LOGFILE,
	     this_player()->query_real_name() + " refunded key, at time:" +
	     ctime(time()) + ".\n"); */
	move_object(key,this_player());
	say("Estate agent says: Strange, you seem to have lost your key.\n" +
	  "Have this one as a replacement...\n",
	  this_object());
	write("Estate agent says: Strange, you seem to have lost your key.\n" +
	  "Have this one as a replacement...\n");
	return 1;
    }
    write("He suddenly seems very enthusiastic when you enter the room,\n");
    write("and starts frantically paging through his folder of property\n");
    write("details.  Why don't you 'ask agent about property'?\n");
    return 1;
}



has_got_key() {
    object thisob;

    thisob = first_inventory(this_player());
    while (thisob) {
	if (thisob->id("house key")) {
	    return 1;
	}
	thisob = next_inventory(thisob);
    }
    return 0;
}


get() {
    return 0;     /* may not be picked up */
}


drop() {
    return 1;     /* may not be dropped */
}


query_weight() {
    return 0;     /* weightless  */
}


query_value() {
    return 0;     /* may not be sold */
}


reset(arg) {
    if (arg) {
	return;
    }
    revenue_so_far = 0;
}



init() {
    add_action("ask", "ask");
    add_action("buy", "buy");
    if (this_player()->query_level() > 30) {
	add_action("agent_stats","agent_stats");
    }
}



agent_stats() {
    write("agent statistics:\n");
    write("File name:     " + file_name(this_object()) + ".\n");
    write("Total revenue: " + revenue_so_far           + ".\n");
    return 1;
}



ask(str) {
    string discard;

    if (!str) {
	return;
    }
    if ((sscanf(str,"agent about propert%s", discard) != 1)        &&
      (sscanf(str,"estate agent about propert%s", discard) != 1)) {
	return;
    }
    say(this_player()->query_name() + " asks the estate agent something.\n",
      this_player());
    write("Estate agent tells you: I can sell you this wonderfull little\n" +
      "house, which you can redecorate yourself if you like, that will\n" +
      "_always_ be available for you to enter.  Naturally, security\n");
    write("and privacy can be guaranteed.  It has three rooms, with rapid\n");
    write("transport between the entrance and the church, for you and those\n");
    write("you invite to visit.\n");
    write("The cost is a mere " + HOUSECOST + " gp, which for a perpetual\n");
    write("ownership deal, is extremely favourable.\n");
    write("If you wish to add more rooms to your house, (up to a maximum\n");
    write("of 10), then the builder's will charge you " + ROOMCOST + " gp.\n");
    write("Just 'buy house', and I can give you the key immediately.\n");
    return 1;
}


buy(str) {
    object key;
    string name;
    name = this_player()->query_real_name();

    if (!str || ((str != "house") && (str != "property"))) {
	return 0;
    }
    say(this_player()->query_name() + " tries to buy a new house.\n",
      this_player());
    if (has_got_key()) {
	write("But you ALREADY have a house!\n");
	say("Estate agent says: But you ALREADY have a house?!\n",
	  this_player());
	return 1;
    }
    else if(file_size(sprintf(HOUSES_DIR + "%c" + "/" +
	  "%s" + ".o", name[0], name)) > 0 ) {
	/* sometimes autoloading objects get lost. *sigh* */
	key = clone_object(HOUSEKEY);
	/*   log_file(LOGFILE,
	      this_player()->query_real_name() + " refunded key, at time:" +
	      ctime(time()) + ".\n"); */
	move_object(key,this_player());
	say("Estate agent says: Strange, you seem to have lost your key.\n" +
	  "Have this one as a replacement...\n",
	  this_object());
	write("Estate agent says: Strange, you seem to have lost your key.\n" +
	  "Have this one as a replacement...\n");
	return 1;
    }
    if (this_player()->query_money() < HOUSECOST) {
	write("Estate agent says: But you have insufficient funds!\n");
	say("Estate agent says: But you have insufficient funds!\n",
	  this_player());
	return 1;
    }
    key = clone_object(HOUSEKEY);
    log_file(LOGFILE,
      this_player()->query_real_name() + " HAS JUST BOUGHT A HOUSE.\n" +
      "Cost: " + HOUSECOST + ", at time: " + ctime(time()) + ".\n");
    this_player()->add_money(-HOUSECOST);
    revenue_so_far += HOUSECOST;
    move_object(key,this_player());
    say("Estate agent says: WELL DONE! May you have may happy years in your\n" +
      "new house, I wish you the best.\n",
      this_object());
    write("Estate agent says: WELL DONE! May you have may happy years in\n" +
      "your new house, I wish you the best.\n");
    write("Here's your key, all you have to do is type 'house' from the\n" +
      "church, or a friend's house.\n");
    return 1;
}



add_revenue(arg) {
    revenue_so_far += arg;
}


