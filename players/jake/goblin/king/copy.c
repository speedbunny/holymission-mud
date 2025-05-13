

inherit "room/room";

#include "/players/jake/defs.h"
 object king;
string chat_str, function, type, match;
object hero;
string hero_name;

reset(arg) {
    object obj;
    ::reset(arg);

    if (!chat_str) {
	chat_str = ({
    "The goblin king sighs\n",
    "The goblin king says: Someone has stolen my crown.\n",
    "The goblin king says: I knew that wizards experiments would fail!\n",
    "The goblin king says: His cursed zombies came up here and stole my crown!\n",
	});

	function = allocate(4);
	type = allocate(4);
	match = allocate(4);
	
	function[0] = "handle_say";
	type[0] = "says";
	match[0] = "";
	type[1] = "tells you:";
	match[1] = " ";
	function[2] = "handle_arrival";
	type[2] = "arrives";
	match[2] = "";
	function[3] = "handle_giving";
	type[3] = "gives";
	match[3] = "";
    }

  if (!king) {
king = clone_object("obj/monster");
king->set_name("goblin king");
king->set_alias("king");
king->set_alt_name("goblin");
king->set_short("The Goblin King");
king->set_long("This is the Goblin King.  He rules over all of the goblin land.\n" +
   "He appears to be very powerful and wise.\n" +
   "Something seems to be troubling him at the moment.\n");
king->set_level(20);
king->set_al(250);
king->set_ac(10);
king->set_male();
king->set_spell_mess1("The Goblin King smashes his opponent with his bare fist.");
king->set_spell_mess2("The Goblin King smashes you with his bare fist.  Sharp pain tears through you!");
king->set_chance(20);
king->set_spell_dam(40);

king->load_chat(2, chat_str);
king->set_match(this_object(), function, type, match);

 move_object(king, this_object());

move_object(obj, king);

	obj = clone_object("obj/weapon");
  obj->set_name("heavy mace");
  obj->set_alias("mace");
  obj->set_class(15);
  obj->set_value(2000);
  obj->set_weight(3);
  obj->set_short("A heavy mace");
  move_object(obj, king);
king->init_command("wield heavy mace");

    }
    if (!arg)
    {
       set_light(1);
  DD = ({
     KI + "k3","east",
       });
  short_desc = "The Goblin Kings throne room";
  long_desc = "You have entered the Goblin Kings throne room.  The room is\n" +
   "lavishly decorated with silk tapestries, and beautiful ornaments of all\n" +
   "shapes and sizes.  Luxurious, thick carpet covers the floor.  There are two\n" +
   "thrones that stand against the western wall, but only one seems to be used.\n"  +
   "The empty throne has a small picture that sits on it, and a small plaque\n"  +
   "lies at the base of the throne.  A large chandolier hangs from the ceiling\n"  +
   "and provides a brilliant light to brighten the room.\n";
     }
}


handle_say(str) {
    string who, phrase, a, b;
    object client;

    if (   (sscanf(str, "%s says: %s\n", who, phrase) != 2)
	&& (sscanf(str, "%s says \"%s\"\n", who, phrase) != 2)	/* Morgar's say with quotes! */
	&& (sscanf(str, "%s tells you: %s\n", who, phrase) != 2)) {
say("The Goblin King looks genuinely baffled.\n");
	return;
    }
  if ((who == "goblin king") || (who == "king"))
	return;

    phrase = lower_case(phrase);
    client = present(lower_case(who), environment(king));
    if (!client) {
say("The goblin king looks confused.\n");
	return;
    }

    if (!hero || !present(hero, this_object()))
	handle_arrival(who + " arrives.");
    else if (client != hero) {
say("The Goblin King says: Please leave " + hero_name + " and I alone, " + who + ".  It is very rude to interrupt.\n");
    }
    else if (   sscanf(phrase, "%syes%s", a, b) == 2
	     || sscanf(phrase, "%sok%s", a, b) == 2
	     || sscanf(phrase, "%swill%s", a, b) == 2) {
	
	
say("The Goblin King says:  Thank you, " + who + "!  I am in your debt!\n");
say("The Goblin King has prepared a small speech:\n");
say("   My trusty wizard Shridhar has created a small army of undead goblins\n"  +
    "   to guard our fair city and this castle.  Unfortunately, he has lost\n" +
    "   control of them, and they have escaped captivity and run wild in the\n"  +
    "   caverns below this castle.  One of these zombies, Arrgrath, as he has\n"  +
    "   come to be known has stolen my crown, and uses it to assume command\n"  +
    "   over the rest of the zombies.  I ask of you, " + hero_name + ", to\n"  +
    "   defeat Arrgrath, and return my crown to me.\n");
	
	hero = 0;
	
	
log_file("jake", ctime(time()) + ": " + who +
		 " (level " + client->query_level() +
 ") agreed to retrieve the crownn\n");
	
	}
    }

handle_arrival(str)
{
    string who, rest, n;
    object client;
    int client_level;

    if (sscanf(str, "%s arrives%s", who, rest) != 2) {
say("The goblin king is sleeping.\n");
	return;
    }
    if ((who == "goblin king") || (who == "king"))
	return;

    client = present(lower_case(who), environment(king));
    if (!client) {
say("The goblin king looks baffled.\n");
	return;
    }

    n = call_other(client, "query_name");

    if (present("kings crown",client)) {
say("The goblin king says: Hello there, " + n +"!\n" +
	    "    I see that you have solved your mission!\n" +
    "   If you have my crown, please return it to me me!\n");
	return;
    }

	return;
    }

    client_level = client->query_level();
 say("The goblin king looks at you and says: Hello " + n +".\n"  +
 say("      I am looking for a brave warrior to accomplish a task for me.\n");

    if (hero && present(hero, this_object()) && hero->query_level() > client_level) {
say("   but I think " + hero_name + " is such a warrior.\n");
    }
    else if (client_level < 5) {
	say("     but it's much to dangerous for you, kid. Run along and play now!\n");
    }
    else if (client_level < 8) {
	say("     but, frankly, you are not experienced enough for this kind of mission.\n");
    }
    else if (client_level < 20) {
	say("     and you might just possibly have a chance, even though I would\n" +
	    "     prefer to give this mission to someone with more experience.\n");
	say("     Will you do it?\n");
	hero = client;
	hero_name = who;	
    }
    else if (client_level < 30) {
	say("     and you are just the kind of person I need!\n");
	say("     Will you do it?\n");
	hero = client;
	hero_name = who;
    }
    else {
	say("     and you, Mighty Wizard, can of course do it in no time (grovel, grovel).\n" +
	    "     Feel free to try this little mission,\n" +
	    "     but try not to mess things up for those\n" +
	    "     level 20-29 players who really should be doing it!\n");
	say("     Do you want to do it?\n");
	hero = client;
	hero_name = who;
    }
} /* handle_arrival */

handle_giving(str) {
    string who, what, whom;
 object the_crown, client;

    if (sscanf(str, "%s gives %s to %s.\n", who, what, whom) == 3) {
the_crown = present("kings crown", king);
if(creator(the_crown)!="jake") {
	     log_file("QUESTS.CHEAT",this_player()->query_real_name()+": by "+
             file_name(the_crown)+": goblin_crown: "+ctime(time())+"\n");
             destruct(the_crown);
             return 1;
        }
if (king->id(lower_case(whom)) && the_crown) {
     /*King has his crown now*/
    client = present(lower_case(who), environment(king));
	    if (!client) {
say("The goblin king looks confused.\n");
		return;
	    }
   say("The goblin king says:  Thank you so much for returning my crown to me, " + who + "!\n");
	    say("    Here is your reward, 10000 gold coins!\n");
    tell_object(client, "Goblin King gives you 10000 gold coins.\n");
	    client->add_money(10000);
    say("The Goblin King places the crown upon his head and smiles.\n");
    destruct(the_crown);
    king->add_weight(-8);

/* Mangla: Do not need to log this
	    log_file("padrone", ctime(time()) + ": " + who +
		     " (level " + client->query_level() +
		     ") gave Chaosblade to the secret police Captain!\n");
*/
	    if (!present("sp_membership", client)) {
		badge->set_name(who);
		move_object(badge, client);
	    }
	    say("The captain says: You are now also a full member of the Secret Police!\n");
	    client->set_quest("secret_police");
	}
    }
} /* handle_giving */
