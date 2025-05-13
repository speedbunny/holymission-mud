inherit "/players/whisky/seaworld/monster/monster.c";

int count;

reset(arg) {
        ::reset(arg);
     if (arg) return;
	  load_chat(12,({
	    "Rudi says: Bah! Whisky's area is terrible!\n",
	    "Rudi says: Whisky's code is very very messy.\n",
	    "Rudi says: You know, Whisky has many illegal items.\n",
	    "Rudi asks: What are you waiting for?\n",
            "Rudi says: Don't complain about the beer-you'll be old and\n"+
                        "weak yourself one day.\n",
            "Rudi says: Beat inflation, eat the rich.\n",
            "Rudi falls down laughing.\n",
            "Rudi says: Skinheads have more hair than brain.\n",
            "Rudi says: Those monsters are hard nearly as my hard-on.\n",
            "Rudi says: Preserve wildlife-pickle a squirrel.\n",
            "Rudi says: Sometimes I am a bit gay.\n",
            "Rudi kisses you softly.\n",
            "Rudi giggles happily.\n",
            "Rudi says: Sterility is hereditary.\n",
            "Rudi cuddles you shamelessly.\n",
            "Rudi says: Just think--maybe the Jonses are trying to keep\n"+
                       "up with you.\n",
            "Rudi says: Meat is murder.\n",
            "Rudi says: Liquid lunches are the norm in our office.\n",
            "Rudi says: sdrawkab is backwards spelt backwards.\n",
            "Rudi says: Vampires are a pain in the neck.\n",
            "Rudi says: Just destroy the mountains and have a sight to the sea.\n",
            "Rudi says: Smile, they said, life could be worse. So I did and it was.\n", 
	    "Rudi says: Hello there!\n",
	    "Rudi asks: Have you seen `Terminator 2' ?\n",
            "Rudi says: Every time you sleep with a girl, you sleep with all her boyfriends.\n",
            "Rudi says: Reincarnation is a pleasant surprise.\n",
            "Rudi says: cooooolllllllllll.\n",
            "Rudi says: brb.\n",
            "Rudi says: How old are you ?\n",
            "Rudi says: WAIT !!!!!!!\n",
	    "Rudi asks: Have you seen `Terminator' ?\n",
            "Rudi says: Well, I don't think about THAT!\n",
	    "Rudi says: Go and explore my new castle!\n",
            "Rudi says: My Dark castle lies east of the Eastroad Inn.\n",
            "Rudi says: Hows the weather in Uganda ?\n",
            "Rudi says: A friend of mine is Wiz.\n",
            "Rudi says: These pubs are overpriced.\n",
            "Rudi says: Do you know Elvis Prezzzly.\n",
            "Rudi lets off a real rip roarer.\n",
            "Rudi says: Tell me something about your childhood.\n",
            "Rudi says: Are you in a hurry ?\n",
            "Rudi says: BUUUUUUUUUhhhhhhhhhhhhhhhhhhhhhhhhhhhh.\n",
            "Rudi says: Video, the best idea since rainy days were created!\n",
	    "Rudi asks: My, don't I know you from the party last night?\n",
	    "Rudi asks: Why do you look like that?\n",
	    "Rudi asks: What are you doing here?\n",
            "Rudi says: He's dead, Jim!\n",
            "Rudi says: Have you seen THAT ...\n",
            "Rudi says: Schubidubi wabwab uuuaahh...\n",
            "Rudi says: Hasta la vista, babe!\n",
            "Rudi says: Have you ever been to Carlifornia?\n",
            "Rudi says: This mud here is really cool.\n",
            "Rudi says: Just tell me something about your father.\n",
            "Rudy says: Hey, can I borrow some money for a drink?\n",
            "Rudi says: I'm feelin' so depressed, can you help me?\n",
            "Rudi says: It's  u n b e l i e v a b l e !\n",
            "Rudi says: Huh? What are you talking about?\n",
            "Rudi asks: Do you think you are able to kill this monster?\n",
            "Rudi asks: By the way, d'you know what time it is?\n",
            "Rudi says: Thank god!\n",
            "Rudi says: One moment please.\n",
            "Rudi says: Forget it!\n",
            "Rudi says: Yes, indeed!\n",
            "Rudi says: Sorry! I'm afraid I can't do that.\n",
            "Rudi says: I don't know!\n",
            "Rudi says: Well, ask me that again, tomorrow.\n",
            "Rudi answers: Yes!\n",
            "Rudi answers: No!\n",
            "Rudi answers: Maybe.\n",
            "Rudi says: Tomorrow.\n",
            "Rudi says: Yesterday.\n",
            "Rudi says: Use the force, Luke!\n",
            "Rudi says: Look at the source, Luke!\n",
            "Rudi says: Well, let's have some fun..\n",
            "Rudi asks: Are you afraid of that?\n",
            "Rudi says: Sheesh, students!!!  Think they know everything.\n",
            "Rudi says: Forget him! You can't win the fight against HIM!\n",
            "Rudi says: I hate football, but I like chess.\n",
            "Rudi says: Boy, am I glad that it's only 1968...\n",
            "Rudi says: ???\n",
            "Rudi says: I'll be back in time.\n",
            "Rudi states: Always these problems with stupid players... ugh!\n",
            "Rudi says: I want a new color TV!!!\n",
            "Rudi says: You know how to keep a secret? Fine, me too!\n",
            "Rudi says: Only one minute and I'll be okay again.\n",
            "Rudi says: Ouh! I really feel sick. Please fetch me some water.\n",
            "Rudi says: Some days ago I watched `Predator 2' on video.\n",
            "Rudi says: Close your eyes and turn around...\n",
            "Rudi says: Gotcha!\n",
            "Rudi says: I'll follow you for a while.\n",
            "Rudi says: Don't take it that hard!\n",
            "Rudi says: Thank you very much!\n",
            "Rudi says: Hey! Don't run so fast!\n",
            "Rudi asks: Time for a party, don't you think so?\n",
            "Rudi says: Let's go to the pub and have a drink!\n",
            "Rudi asks: Can't you hear the siren? It must be an alarm!\n",
            "Rudi says: Beware! They're coming, coming to get YOU...\n",
            "Rudi says: Welcome stranger!\n",
            "Rudi says: Well, stop talking, start solving your quests.\n",
            "Rudi makes a magical gesture and something happened!\n",
            "Rudis appearance seems to change a bit.\n",
	    "Rudi smiles mysterically at you.\n",
            "Rudi hits the deck with his hands behind his neck.\n",
            "Rudi tries to summon a Jabberwocky but fails to do so.\n",
            "Rudi combs his hair with a black bug-rake.\n",
            "Rudi sits down on the ground and meditates about life and MUD!\n",
            "Rudi opens a pocket, picks a cigarette and lights it.\n",
            "Rudi picks a strange new object from the ground.\n",
            "Rudi turns around and looks at someone in the distance.\n",
            "Rudi greets you and shakes your hands.\n",
            "Rudi pats you on your head ... PAT PAT PAT\n",
            "Rudi starts step-dancing.\n",
            "Rudi takes his glasses and cleans them.\n",
            "Rudi fetches a chair from nowhere and sits down.\n",
            "Rudi gets up from the ground.\n",
            "Rudi winks suggestively at SomeThinG.\n",
            "Rudi blushes.\n",
            "Rudi looks puzzled.\n",
            "Rudi looks confused.\n",
            "Rudi tips you at your shoulder.\n",
            "Rudi looks you in the eyes.\n",
            "Rudi whispers something to SomeThinG.\n",
            "Rudi shakes hands with SomeThinG.\n",
            "Rudi stomps with his right leg a bug into the ground.\n",
            "Rudi changes the fabric of space.\n",
            "Rudi rolls his eyes to the ceiling and faints to the ground.\n",
            "Rudi starts wondering about what happened lately.\n",
            "Rudi says: Scotty, it's time .. get me out of here .. NOW!\n",
            "Rudi closes his eyes.\n",
            "Rudi opens his eyes.\n",
            "Rudi picks an apple.\n",
            "Rudi sniffs.\n",
            "Rudi growls.\n",
            "Rudi thanks you.\n",
            "Rudi smiles.\n",
            "Rudi giggles inanely.\n",
            "Rudi claps on your shoulder.\n",
            "Rudi falls down laughing.\n",
            "Rudi waits patiently...\n",
            "Rudi snaps with his fingers.\n",
            "Rudi sobs.\n",
            "Rudi nods solemnly.\n",
            "Rudi gasps in real astonishment.\n",
            "Rudi gasps in astonishment.\n",
	    "Rudi bows to his audience.\n",
            "Rudi burps rudely.\n",
            "Rudi whistles appreciatively.\n",
            "Rudis face turns pale as ashes.\n",
            "Hic!  Rudi hiccups.\n",
            "Rudi apologizes himself.\n",
            "Rudi spits on the ground.\n",
            "Rudi kicks you.\n",
            "Rudi scratches his head and considers the problem!\n",
            "Rudi leaves NOT to the east.\n",
            "Rudi pokes you in the ribs.\n",
            "Rudi sits comfortably down and relaxes.\n",
            "Rudi bangs his head against the next wall.\n",
            "Rudi pokes you in the eye ... Ouuch that HURTS!\n",
            "Rudi scratches his head.\n",
            "Rudi shakes hands with everybody.\n",
            "Rudi tries to solve the riddle of the Sphinx.\n",
	  }));
	  load_a_chat(40,({
	    "Rudi says: You shouldn't do that, kid!\n",
            "Rudi says: Stop that or I'll zap you..\n",
	    "Rudi says: Don't you EVER do that again!\n",
	    "Rudi says: I'm a wizard, didn't you know that?\n",
	    "Rudi says: Go messin'round with the other players!\n",
	    "Rudi says: It's enough. I'll zap you in 3 seconds...\n",
	    "Rudi says: I didn't thought players could be so foolish.\n",
	    "Rudi says: Get out of my way!! There's work to be done!\n",
	    "Rudi says: C'mon punk! Make my day....\n",
            "Rudi says: Enough is enough!\n",
            "Rudi says: One more time and...\n",
            "Rudi says: This is from me to you.\n",
            "Rudi says: That's it,    Freddy    get this one now!\n",
            "Rudi puts a curse on you.\n",
            "Rudi curses and makes some violent gestures.\n",
            "Rudi kicks you in the guts ... Ouuuch, that HURTS!!\n",
            "Rudi makes a magical gesture and you start feeling weak.\n",
            "Rudi looks with great eyes ... over your shoulder.\n",
            "Rudi touches your nose and bangs on your head.\n",
	  }));
	  load_match(this_object(),
		     ({
		       "why_did",		({"sells","attack","left",({"the game"}),"takes","drops"}),
		       "how_does_it_feel",	({"is now level"}),
		       "smiles",		({"smiles",({" happily."})}),
		       "say_hello",		({"arrives"}),
		       "test_say",		({"says: ","tells you:"}),
		       "follow",		({"leaves"}),
		       "gives",			({"gives"}),
		     }));
	set_name("rudi");
	set_alias("aldo");
	set_short("Rudi the small adventurer (nasty)");
	set_long("Rudi the small adventurer (nasty)\n"+
                 "He has a scar on his right hand, left foot and cheek.\n"); 
        set_level(4);
        set_hp(200);
        add_money(random(400));
        set_whimpy();
	set_al(-100);
	set_aggressive(0);
	set_move_at_reset(0);
}

why_did(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "fastkill" || who == "Rudi")
	return;
    if (sscanf(str, "%s sells %s.", who, what) == 2) {
	notify("Rudi says: Why did you sell " + what + "\n");
    }
    if (sscanf(str, "%s attacks %s.", who, what) == 2) {
	notify("Rudi says: Why does " + who + " attack " + what + "?\n");
    }
    if (sscanf(str, "%s left the game.", who) == 1) {
	notify("Rudi says: Why did " + who + " quit the game ?\n");
    }
    if (sscanf(str, "%s takes %s.\n", who, what) == 2) {
	notify("Rudi says: Why did " + who + " take " + what + " ?\n");
    }
    if (sscanf(str, "%s drops %s.\n", who, what) == 2) {
	notify("Rudi says: Why did " + who + " drop " + what + " ?\n");
        if (random(100)<20) { command("get all"); }
    }
}

notify(str) {
    say(str);
    write(str);
}
	
how_does_it_feel(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "fastkill" || who == "Rudi")
	return;
    if (sscanf(str, "%s is now level %s.\n", who, what) == 2) {
	notify("Rudi says: How do you like it, being of level " + what +
	       " ?\n");
    }
}
    
smiles(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
    if(who == "rudi" || who == "rudi")
	return;
    if (sscanf(str, "%s smiles happily", who) == 1 &&
	who != "Rudi") {
	notify("Rudi smiles.\n");
    }
}
    
say_hello(str) {
    string who;
    if (sscanf(str, "%s arrives.", who) == 1) {
	notify( "Rudi says: Hi " + who + ", nice to see you !\n");
    }
}
    
test_say(str) {
    string a, b, message;

    sscanf(str, "%s %s", a, b);
    if(a == "whisky" || a == "Rudi")
	return;
    if (!sscanf(str, "%s says: %s\n", a, b) == 2) {
	return;
    }
    str = b;

    if (str == "hello" || str == "hi" || str == "hello everybody") {
	message = "Rudi says: Pleased to meet you!\n";
    }
    if (str == "shut up") {
	message = "Rudi says: Why do you want me to shut up ?\n";
    }
    if (sscanf(str, "%sstay here%s", a, b) == 2 ||
	sscanf(str, "%snot follow%s", a, b) == 2 ||
	sscanf(str, "%sget lost%s", a, b) == 2) {
	message = "Rudi says: Ok then.\n";
    }
/*    if(!message)
	message = "Rudi says: Why do you say that???\n";
    notify(message); */
}

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
        command(where);
}

gives(str) {
    string who, what, whom;
    int rand;
    object obj, next_obj;
    if(sscanf(str, "%s gives %s to %s.\n", who, what, whom) != 3)
	return;
    if(whom != "Rudi")
	return;
    if(what == "firebreather" || what == "special" ||
       what == "beer" || what == "bottle") {
	rand = random(4);
	if(rand == 0) {
	    if(random(10) > 6) {
		notify("Rudi sighs and says: I guess I'm NOT going to drink that now.\n");
		obj = first_inventory(me);
		while(obj) {
		    next_obj = next_inventory(me);
		    transfer(obj, environment(me));
		    notify("Rudi drops " + obj->short() + ".\n");
		    obj = next_obj;
		}
		init_command("west");
	    }
	}
	if(rand == 1) {
	    init_command("drink " + what);
	}
	if(rand == 2) {
	    obj = first_inventory(me);
	    while(!obj->id(what))
		obj = next_inventory(obj);
	    transfer(obj, environment(me));
	    notify("Rudi drops the " + what + ".\n");
	}
	if(rand == 3) {
	    obj = first_inventory(me);
	    while(!obj->id())
		obj = next_inventory(obj);
	    transfer(obj, find_living(lower_case(who)));
	    notify("Rudi returned the " + what + " to " + who + ".\n");
	}
    } else if(what == "corpse") {
	notify("Rudi says: HEY, bury your corpses yourself!\n");
	obj = first_inventory(me);
	while(!obj->id(what))
	    obj = next_inventory(obj);
	transfer(obj, find_living(lower_case(who)));
	notify("Rudi returned the " + what + " to " + who + ".\n");
    } else {
	notify("Rudi says: Well, thank you!\n");
    }
  }

