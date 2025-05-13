/*  sheriffs_office.c -- The Sheriff's Office in the Castle of Padrone.
 *  Version: 1.5 (June 22, 1991)
 *
 *  To put a reward on a player, call wanted() with three arguments:
 *	the player object
 *	a string describing the crime (like "the murder of a mermaid")
 *	a reward (if 0 or too high, a default is used)
 */
/* 090794: Nokey: strict_typed */

#pragma strict_types

inherit "room/room";

void setup_arrays();
object find_item_in_player(string itemstring);
int is_wanted(string monstername);
int reward_and_remove(string monstername);

#include "/players/padrone/config.h"

object sheriff;
string criminals;
string poster_text;
string global_crime;
int global_reward;
string bandits_name;

/* For the NEW, IMPROVED monster class: */

mixed function, type, match;

void extra_reset(int arg) {
    object sword;
    if (!arg) {
	criminals = "";
	global_crime = 0;
	global_reward = 0;
    }
    if (!sheriff || !living(sheriff)) {
	sheriff = clone_object("obj/monster");	/* NEW, IMPROVED monster class! */
	sheriff->set_name("sheriff");
	sheriff->set_level(10);
	sheriff->set_male();
	sheriff->set_hp(200);
	sheriff->set_al(300);
	sheriff->set_short("The Sheriff");
	sheriff->set_long("This is the local Sheriff.\n" +
			  "He is old and tough. Before assuming this office he travelled\n" +
			  "the world, thus becoming an experienced warrior.\n");
	sheriff->set_aggressive(0);
	sheriff->set_spell_mess1("The sheriff yells: Criminal! You'll hang for this!");
	sheriff->set_spell_mess2("The sheriff yells: Criminal! You'll hang for this!");
	sheriff->set_chance(20);
	sheriff->set_spell_dam(30);

	/* The NEW, IMPROVED monster calls: */
	if (!function)
	    setup_arrays();
	sheriff->set_match(this_object(), function, type, match);
	move_object(sheriff, this_object());

       move_object((object)"players/padrone/outside/front_yard"->make_ticket(), sheriff);

	sword = clone_object("obj/weapon");
	sword->set_name("short sword");
	sword->set_class(15);
	sword->set_value(700);
	sword->set_weight(2);
	sword->set_alt_name("sword");
	sword->set_short("A short sword");
        move_object(sword, sheriff);
	sheriff->init_command("wield sword");
    }
} /* extra_reset */


void init() {
  ::init();
    add_action("sell", "sell");
    add_action("wantedstat", "wanted");
    add_action("do_exit", "exit");
    add_action("do_exit", "out");
}

int do_exit() {
    this_player()->move_player("out#players/padrone/inside/courtyard");
    return 1;
}


void reset(int arg)
  {
  ::reset(arg);
  extra_reset(arg);
  if(arg) return;
  set_light(1);
  dest_dir = ({"players/padrone/inside/courtyard","west",
  });
  short_desc = "Sheriff's Office";
  long_desc =
	 "You are in the local Sheriff's Office. There is a banner\n" +
	 "on the wall saying 'PROTECT THE WEAK AND INNOCENT'.\n" +
	 "Since some monsters have become a virtual plague in this part\n" +
	 "of the country, the local authorities have decided to pay money\n" +
	 "to those who kill them. These rewards are as follows:\n" +
	 "    dead orc:         10 gold pieces\n" +
	 "    dead orc shaman:  80 gold pieces\n" +
	 "    dead troll:       50 gold pieces\n" +
	 "    dead bird:        10 gold pieces\n" +
	 "You can also be rewarded for killing dangerous criminals.\n" +
	 "Use the command 'wanted' to list these criminals.\n" +
        "You can collect your reward by using the 'sell' command.\n";
  }



int sell(string itemstring) {
    string desc, monstername;
    int value;
    object the_item;

    if (!itemstring)
	return 0;
    if (!sheriff || !living(sheriff)) {
	write("There is no one here to give you money!\n");
        return 1;
    }
    the_item = present(itemstring);
    if (!the_item)
      the_item = find_item_in_player(itemstring);
    if (!the_item) {
	write("No such item ("); write(itemstring); write(") here.\n");
	return 1;
    }
    desc = (string)the_item->short();
    if (sscanf(desc, "Corpse of %s",  monstername) != 1)
	if (sscanf(desc, "corpse of %s",  monstername) != 1)
	    if (sscanf(desc, "The somewhat decayed remains of %s",  monstername) != 1) {
		write("But that is not a dead monster.\n");
		return 1;
	    }
    write("You show the sheriff the dead " + monstername + ".\n");
    if (monstername == "Orc")
	value = 10;
    else if (monstername == "Shaman")
	value = 80;
    else if (monstername == "Troll")
	value = 50;
    else if (monstername == "Bird") {
	write("The Sheriff says: Ah, one of those! Very well done!\n" +
	      "You have done the community a great service by eliminating\n" +
	      "one of those disgusting little bastards.\n");
	value = 10;
    }
    else if (is_wanted(monstername)) {
	write("Sheriff says: Well done! That was a dangerous desperado!\n");
	value = reward_and_remove(monstername);
    }
    else {
	value = 0;
	write("Sorry, no reward for those monsters.\n");
	return 1;
    }

    if (environment(the_item) == this_player()) {
        int weight;
	if (the_item->drop()) {
	    write("I can't take it from you!\n");
	    return 1;
	}
        weight = (int)the_item->query_weight();
	this_player()->add_weight( - weight);
    }
    if (value==1) 
	write("You get 1 gold coin.\n");
    else
	write("You get "); write(value); write(" gold coins.\n");
    say(this_player()->query_name() +
	" collects his reward for a dead " +
	monstername + 
	".\n");
    this_player()->add_money(value);
    destruct(the_item);
    return 1;
}

object find_item_in_player(string i)
{
    object ob;

    ob = first_inventory(this_player());
    while(ob) {
        if (ob->id(i))
	    return ob;
	ob = next_inventory(ob);
    }
    return 0;
}

/* Call these functions to put a reward on a player! */

void set_crime(string str)
{
    global_crime = str;
}

void set_reward(int sum)
{
    global_reward = sum;
}

int wanted(object bandit, string crime, int reward)
{
    object poster;
    int bandits_level, default_reward;
    string bandits_title;


    if (!crime)
	crime = global_crime;
    if (!reward)
	reward = global_reward;
    global_crime = 0;
    global_reward = 0;

    if (!bandit || !objectp(bandit) || bandit->query_npc() || !crime)
	return 0;
    bandits_name = (string)bandit->query_name();
    if (bandits_name == "Someone")
	return 0;

    if (is_wanted(bandits_name)) {

	tell_object(bandit, "\n    If you hadn't already been wanted by the police, you would have been now.\n\n");

	return 0;
    }

    bandits_level = (int)bandit->query_level();
    /* 100 gc per level number, accumulative: */
    default_reward = (bandits_level + 1) * bandits_level * 50;
    if (!reward || reward > default_reward)
	reward = default_reward;

    criminals = criminals + bandits_name + " " + reward + " " + crime + "\n";

    bandits_title = (string)bandit->query_title();

    tell_object(bandit, "\n    Suddenly you feel hunted. Maybe you just did something stupid?\n");
    tell_object(bandit, "    It might be a good idea to avoid the police in the future.\n\n");

#define PUT_POSTER(room) \
    poster = clone_object("players/padrone/obj/wanted_poster"); \
    poster->init_poster(bandits_name, bandits_title, bandits_level, crime, reward); \
    move_object(poster, room);

    PUT_POSTER("players/padrone/workroom")
    PUT_POSTER("players/padrone/inside/sheriffs_office")
    PUT_POSTER("players/padrone/outside/front_yard")
    PUT_POSTER("players/padrone/secret_police/office")
    PUT_POSTER("players/padrone/walker/gate_room")

#ifdef GENESIS
    PUT_POSTER("players/ingis/lane_3")
    PUT_POSTER("players/ingis/milkbar")
#endif

#ifdef NANNY
    PUT_POSTER("players/ingis/lane_3")
    PUT_POSTER("players/ingis/milkbar")
    PUT_POSTER("players/padrone/deposit/deposit")
    PUT_POSTER("room/post")
    PUT_POSTER("players/ketchup/towngate")
    PUT_POSTER("players/charles/town_square")
#endif

    return 1;
} /* wanted */


int wantedstat() {
    string rest, this_name, this_crime;
    int this_reward, n;

    if(criminals != "")
      write("The following persons are wanted:\n");
    else write("No one is wanted at this time.\n");
    rest = criminals;
    while (rest != "") {
	n = sscanf(rest, "%s %d %s\n%s", this_name, this_reward, this_crime, rest);
	if (n == 3)
	    rest = "";
	else if (n != 4) {
	    write("Sorry. List of criminals is corrupt. All deleted.\n");
	    criminals = "";
	    return 1;
	}
	write("    " + this_name + " is wanted for " + this_crime +
	      ".\n        The reward is " + this_reward + " gold coins.\n");
    }
    return 1;
}

int is_wanted(string name) {
    string junk1, junk2;

    return (sscanf(criminals, "%s"+name+"%s", junk1, junk2) == 2);
}

int reward_and_remove(string name) {
    string rest;
    int sum;
    int n;
    string this_name, this_crime;
    int this_reward;

    write("The sheriff looks at his notes.\n");
    sum = 0;
    rest = criminals;
    criminals = "";
    while (rest != "") {
	n = sscanf(rest, "%s %d %s\n%s",
		   this_name, this_reward, this_crime, rest);
	if (n == 3)
	    rest = "";
	else if (n != 4) {
	    write("Sorry. List of criminals is corrupt. All deleted.\n");
	    return 0;
	}
	if (this_name == name) {
	    write(name + " is wanted for " + this_crime +
		  ". The reward is " + this_reward + ".\n");
	    sum += this_reward;
	}
	else
	    criminals = criminals + this_name + " " + this_reward + " " +
		this_crime + "\n";
    }
    return sum;
}


/* For the NEW, IMPROVED monster class: */
void setup_arrays() {

    function = allocate(1);
    type = allocate(1);
    match = allocate(1);

    function[0] = "handle_arrival";
    type[0] = "arrives";
    match[0] = "";
} /* setup_arrays */


void handle_arrival(string str) {
    string who, rest;
    object suspect;

    if (sscanf(str, "%s arrives%s", who, rest) != 2)
	return;		/* Some strange error! */
    suspect = present(lower_case(who), environment(sheriff));
    if (!suspect)
	return;		/* Already gone! */
    if (!present("castle ticket", suspect)) {
	/* A player/monster without a ticket has arrived! -- ATTACK! */
	say("Sheriff immediately notices that " +
	    who + " hasn't got a ticket.\n");
	sheriff->attacked_by(suspect);
    }
    if (is_wanted(who)) {
	say("Sheriff says: " + who + ", you are a criminal! Die for your evil deeds!\n");
	sheriff->attacked_by(suspect);
    }
} /* handle_arrival */
