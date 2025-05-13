inherit "/room/room"; 

object captain;
string chat_str, function, type, match;
object hero;
string hero_name;

reset(arg) {
    object obj;
    ::reset(arg);

    if (!chat_str) {
        chat_str = ({
            "General says: The orcs have been building an army.\n",
            "General says: We are running low on supplies.\n",
         "General says: It is just a matter of time before the orcs invade.\n",
            "General says: All but my most loyal men have deserted.\n",
            "The general looks tired and worn.\n",
            "General says: We have fought them off, but this time there are just too many.\n"
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

    if (!captain) {
        captain = clone_object("obj/monster");
        captain->set_name("general");
        captain->set_alias("wolfen general");
        captain->set_alt_name("soldier");
        captain->set_short("wolfen general");
        captain->set_long("A wolfen soldier, he eyes your throat hungrily.\n" +
                          "You notice several markings of honor upon his\n" +
                          "clothing that identify him as a general.\n");
        captain->set_level(40);
        captain->set_al(50);
        captain->set_ac(60);
        captain->set_male();
        captain->set_spell_mess1("The general grins, and bites his opponent.");
        captain->set_spell_mess2("As you admire the general's big teeth, he grins and bites you.");
        captain->set_chance(40);
        captain->set_spell_dam(70);
        captain->load_chat(2, chat_str);
        captain->set_match(this_object(), function, type, match);
        move_object(captain, this_object());

        /* obj = clone_object("players/padrone/secret_police/membership"); 
           move_object(obj, captain); 
           obj->set_name("captain"); */

        obj = clone_object("obj/weapon");
        obj->set_name("a heavy sword");
        obj->set_alias("longsword");
        obj->set_alt_name("sword");
        obj->set_class(19);
        obj->set_value(2000);
        obj->set_weight(4);
        obj->set_short("A long, heavy sword");
        move_object(obj, captain);
        captain->init_command("wield sword");

    }
    if (!arg)
    {
       set_light(1);
       dest_dir =
       ({
           "players/padrone/secret_police/hall", "south",
       });
       short_desc =  "The wolfen general's quarters";
       long_desc =
         "A comfortable looking bedroom.  In the center is a small tent\n" +
         "made out of bedsheets.  Inside this tent, is a cushion made up\n" +
         "like a bed.  There are a few flat stones, covered with cloth,\n" +
         "for furnature.\n";
    }
}

handle_say(str) {
    string who, phrase, a, b;
    object client;

    if (   (sscanf(str, "%s says: %s\n", who, phrase) != 2)
        && (sscanf(str, "%s says \"%s\"\n", who, phrase) != 2)  /* Morgar's say with quotes! */
        && (sscanf(str, "%s tells you: %s\n", who, phrase) != 2)) {
        say("General says:  Dammit, speak in English!\n");
        return;
    }
    if ((who == "The captain") || (who == "Captain"))
        return;

    phrase = lower_case(phrase);
    client = present(lower_case(who), environment(captain));
    if (!client) {
        say("The captain looks confused.\n");
        return;
    }

    if (!hero || !present(hero, this_object()))
        handle_arrival(who + " arrives.");
    else if (client != hero) {
        say("The captain says: Please be quiet, " + who + ". I am talking to " + hero_name + ".\n");
    }
    else if (   sscanf(phrase, "%syes%s", a, b) == 2
             || sscanf(phrase, "%sok%s", a, b) == 2
             || sscanf(phrase, "%swill%s", a, b) == 2) {
        
        object orders, badge;
        
say("The captain says: Thank you, " + who + "! This country will not forget you!\n");
        say("The captain has prepared a small speech:\n");
  say("    The well-known wizard Padrone, sometimes known as the Wizard of\n" +
      "    (hah!) Law and Balance, has captured a demon of chaos. In his usual\n" +
            "    megalomaniac stupidity he didn't kill it, but just put it in a\n");
        say("    cell in his (in)famous walking castle. There is even a rumour that\n" +
            "    he did this only to use the demon as a guard for his money!\n" +
            "    That demon is an abomination and a threat, and it must be killed!\n");
        
        hero = 0;
        
        orders = clone_object("players/padrone/secret_police/orders");
        orders->init_orders(who);
        move_object(orders, client);
        
        log_file("padrone", ctime(time()) + ": " + who +
                 " (level " + client->query_level() +
                 ") got the secret police orders.\n");
        
        say("The captain says: Here are your orders");
        if (!present("sp_membership", client)) {
            badge = clone_object("players/padrone/secret_police/membership");
            badge->set_name(who);
            badge->set_temporary(1);
            move_object(badge, client);
            say(", and your Secret Police membership");
        }
        say(".\n");
        say("    Report back here as soon as your mission is completed!\n");
    }
    else if (   (sscanf(phrase, "%sno%s", a, b) == 2)
             || (sscanf(phrase, "%sdanger%s", a, b) == 2)
             || (sscanf(phrase, "%ssorry%s", a, b) == 2)
             || (sscanf(phrase, "%swon't%s", a, b) == 2)) {
        say("The captain says: Bah! Coward!\n");
    }
    else {
        say("The captain says: What? What are you talking about?\n");
    }
} /* handle_say */

handle_arrival(str)
{
    string who, rest, n;
    object client;
    int client_level;

    if (sscanf(str, "%s arrives%s", who, rest) != 2) {
        say("The captain looks brain damaged.\n");
        return;
    }
    if ((who == "The captain") || (who == "Captain"))
        return;

    client = present(lower_case(who), environment(captain));
    if (!client) {
        say("The captain looks confused.\n");
        return;
    }

    n = call_other(client, "query_name");

    if (present("chaosblade of death", client)) {
        say("The captain says: Ah! Welcome back, " + n + "!\n" +
            "    I see that you have solved your mission!\n" +
            "    Now give that evil sword of chaos to me!\n");
        return;
    }

    if (present("sp_orders", client)) {
        say("The captain says: What are you doing here, " + n + "?\n" +
            "    You have an important mission to do! Don't just stand there! Move! Move!\n");
        return;
    }

    client_level = client->query_level();
    say("The captain looks up from his papers and says: Welcome, " + n + "!\n");
    say("     I am looking for a person for a very special mission,\n");

    if (hero && present(hero, this_object()) && hero->query_level() > client_level) {
        say("     but I think " + hero_name + " here can do it.\n");
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
    object the_chaosblade, client, badge;

    if (sscanf(str, "%s gives %s to %s.\n", who, what, whom) == 3) {
        the_chaosblade = present("chaosblade of death", captain);
        if(creator(the_chaosblade)!="padrone") {
             log_file("QUESTS.CHEAT",this_player()->query_real_name()+": by "+
             file_name(the_chaosblade)+": secret_police: "+ctime(time())+"\n");
             destruct(the_chaosblade);
             return 1;
        }
        if (captain->id(lower_case(whom)) && the_chaosblade) {
            /* Gave the Chaosblade to the captain, and he has it now. */
            client = present(lower_case(who), environment(captain));
            if (!client) {
                say("The captain looks utterly confused.\n");
                return;
            }
            say("The captain says: You have done your country a great service, " + who + "!\n");
            say("    Here is your reward, 10000 gold coins!\n");
            tell_object(client, "Captain gives you 10000 gold coins.\n");
            client->add_money(10000);
            say("The captain sends the Chaosblade away for destruction.\n");
            destruct(the_chaosblade);
            captain->add_weight(-8);

/* Mangla: Do not need to log this
            log_file("padrone", ctime(time()) + ": " + who +
                     " (level " + client->query_level() +
                     ") gave Chaosblade to the secret police Captain!\n");
*/
            badge = present("sp_membership", client);
            if (!present("sp_membership", client)) {
                badge = clone_object("players/padrone/secret_police/membership");
                badge->set_name(who);
                /* badge->set_temporary(1); */
                move_object(badge, client);
            }
            badge->set_temporary(0);
            say("The captain says: You are now also a full member of the Secret Police!\n");
        /* HERP: set the quest to solved */
            client->set_quest("secret_police");
        }
    }
} /* handle_giving */
