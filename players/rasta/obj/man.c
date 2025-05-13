
object ras;
int count;
string chat_str;	/* This variable is only initialized once. */
string a_chat_str;
string function, type, match;

reset(arg) {
   start_ras();
    if (arg)
	return;
            

}

start_ras() {
  if(!ras) {
	if (!chat_str) {
	    chat_str = allocate(10);
	    a_chat_str = allocate(8);
chat_str[0] = "The Rastafarian sings a reggae tune.\n";
chat_str[1] = "The Rastaman smokes a huge spliff of ganja.\n";
chat_str[2] = "The Rastafarian says: Jah be with you.\n";
chat_str[3] = "The Rastaman says: Dem cyaan kill prophecy. \n";
chat_str[4] = "The Rastaman says: Come to Trench Town !!!\n";
chat_str[5] = "The Rastaman says: Rastafari lives, Jah is alive !\n";
chat_str[6] = "The Rastaman puts on an iron shirt to chase the devil"
     +"out of earth.\n";

chat_str[8] = "The Rastaman breathes in defiance and victory.\n";
chat_str[9] = "I and I fight dem nefarious Babylon shitstem.\n";
a_chat_str[0] = "The Rastaman says: You can kill I-man, but you cyaan"
  + "kill prophecy.\n";
a_chat_str[1] = "Judgment day is near!\n";
a_chat_str[2] = "The Rastaman shouts: Let me tell you about Marcus Garvey.\n";
a_chat_str[3] = "The Rastaman curses something in Jamaican English.\n"
     + "You don't understand what he says. \n";
a_chat_str[4] = "The Rastaman says: stop fussing and fighting!\n";
a_chat_str[4] = "The Rastaman whirls his dreadlock with pride.\n";
a_chat_str[7] = "The Rastafarian says: see de hypocrite. Dem a galong dey.\n";

	    function = allocate(12);
	    type = allocate(12);
	    match = allocate(12);

	    function[0] = "why_did";
	    type[0] = "sells";
	    type[1] = "attack";
	    type[2] = "left";
	    match[2] = "the game";
	    type[3] = "takes";
	    type[4] = "drops";
	    function[5] = "how_does_it_feel";
	    type[5] = "is now level";
	    function[6] = "smiles";
	    type[6] = "smiles";
	    match[6] = " happily.";
	    function[7] = "say_hello";
	    type[7] = "arrives";
	    function[8] = "test_say";
	    type[8] = "says:";
	    type[9] = "tells you:";
	    function[10] = "follow";
	    type[10] = "leaves";
	    function[11] = "gives";
	    type[11] = "gives";
	}
    }
}

why_did(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
   if(who == "rastaman" || who == "Rastaman")
	return;
    if (sscanf(str, "%s sells %s.", who, what) == 2) {
   notify("The Rastaman says: abandon your materialistic ways !\n");
    }
    if (sscanf(str, "%s attacks %s.", who, what) == 2) {
notify("The Rastaman says: " + who +", "+what+"! Stop fussing and "
        + "fighting!\n");
    }
    if (sscanf(str, "%s left the game.", who) == 1) {
notify("The Rastaman says: Maybe " + who + "is on the way to Zion.\n");
    }
    if (sscanf(str, "%s takes %s.\n", who, what) == 2) {
notify("The Rastaman invites you to see Trench Town.\n");
    }
    if (sscanf(str, "%s drops %s.\n", who, what) == 2) {
notify("The Rastaman invites you to see Trench Town.\n");
    }
}

notify(str) {
    say(str);
    write(str);
}
	
how_does_it_feel(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
  if(who == "rastaman" || who == "Rastaman")

	return;
    if (sscanf(str, "%s is now level %s.\n", who, what) == 2) {
notify("The Rastaman says: Don't deal with any evil establishment.\n");
    }
}
    
smiles(str) {
    string who, what;
    sscanf(str, "%s %s", who, what);
if (who == "rastaman" || who == "Rastaman")
	return;
    if (sscanf(str, "%s smiles happily", who) == 1 &&
  who !="Rastaman") {
  notify("The Rastaman smiles and rolls a huge spliff of sensimilia herb.\n");
    }
}
    
say_hello(str) {
    string who;
    if (sscanf(str, "%s arrives.", who) == 1) {
notify("The Rastaman says: Hello "+who+" do you feel for Africa ?\n");
    }
}
    
test_say(str) {
    string a, b, message;

    sscanf(str, "%s %s", a, b);
if (a == "Rastaman" || a == "rastaman")
	return;
    if (!sscanf(str, "%s says: %s\n", a, b) == 2) {
	return;
    }
    str = b;

    if (str == "hello" || str == "hi" || str == "hello everybody") {
message = "The Rastafarian says: Greetings in the name of Jah, Rastafari!\n";
    }
    if (str == "shut up") {
message = "The Rastaman says: I have to tell you about prophecy!\n";
    }
    if (sscanf(str, "%sstay here%s", a, b) == 2 ||
	sscanf(str, "%snot follow%s", a, b) == 2 ||
	sscanf(str, "%sget lost%s", a, b) == 2) {
message = "The Rastaman says: You can't bribe Jah.\n";
}
}

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
call_other(ras, "init_command", where);
}

gives(str) {
    string who, what, whom;
    int rand;
    object obj, next_obj;
    if(sscanf(str, "%s gives %s to %s.\n", who, what, whom) != 3)
	return;
if(whom != "Rastaman")
	return;
    if(what == "firebreather" || what == "special" ||
       what == "beer" || what == "bottle") {
	rand = random(4);
	if(rand == 0) {
	    if(random(10) > 6) {
notify("The Rastaman says: Alcohol ruins your life!");
obj = first_inventory(ras);
		while(obj) {
next_obj = next_inventory(ras);
transfer(obj,environment(ras));
notify("The Rastaman abandons " + call_other(obj,"short") + ".\n");
		    obj = next_obj;
		}
call_other(ras,"init_command","west");
	    }
	}
	if(rand == 1) {
call_other(ras,"init_command","drink"+what);
	}
	if(rand == 2) {
obj = first_inventory(ras);
	    while(!call_other(obj, "id", what))
		obj = next_inventory(obj);
transfer(obj,environment(ras));
notify("The Rastafarian drops the " + what + ".\n");
	}
	if(rand == 3) {
  obj = first_inventory(ras);
	    while(!call_other(obj, "id", what))
		obj = next_inventory(obj);
	    transfer(obj, find_living(lower_case(who)));
	}
    } else if(what == "corpse") {
obj = first_inventory(ras);
	while(!call_other(obj, "id", what))
	    obj = next_inventory(obj);
	transfer(obj, find_living(lower_case(who)));
    } else {
    }
}

monster_died() {
    object obj, b;
    int num;
obj = first_inventory(ras);
    while(obj) {
b = next_inventory(ras);
	if(call_other(obj, "id", "bottle")) {
	    destruct(obj);
	    num = 1;
	}
	obj = b;
    }
    if(num)
notify("You hear some bottles breaking.\n");
}

down() {
    call_other(this_player(), "move_player", "down#room/station");
    return 1;

}
