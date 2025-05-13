inherit "/players/whisky/seaworld/monster/monster.c";

int count;

reset(arg) {
        ::reset(arg);
     if (arg) return;
	  load_chat(12,({
	    "Rudi says: Bah! Whisky's area is terrible!\n",
            "Rudi tries to solve the riddle of the Sphinx.\n",
	  }));
	  load_a_chat(40,({
	    "Rudi says: You shouldn't do that, kid!\n",
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

