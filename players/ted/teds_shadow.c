#include "security.h"

static object owner;
static object short_arr;
static object mmsgin_arr;
static object mmsgout_arr;

set_owner(ob) { owner = ob; }

new_shadow() { destruct(this_object()); }

start() {
  shadow(owner, 1);
  if(!short_arr) {
    short_arr = allocate(10);
    mmsgin_arr = allocate(5);
    mmsgout_arr = allocate(5);
	short_arr[0] =
"A swirling mass of Chaotic Energy!";
	short_arr[1] =
"A massive cloud of Chaotic Particles!";
	short_arr[2] =
"Chaos on a Global Scale!";
	short_arr[3] =
"Something you've only imagined in your Nightmares!";
	short_arr[4] =
"An Avatar of Chaos, come to Destroy You!";
	short_arr[5] =
"A fuzzy, cute little Teddy Bear";
	short_arr[6] =
"A Big O'l mess of Stuff";
	short_arr[7] =
"You have a suddenly strange suspicion You know this one";
	short_arr[8] =
"An Old Man, bent and withered with age";
	short_arr[9] =
"          A Chaos GOD        ";
	mmsgin_arr[0] =
"With a howl of released energy a swirling mass of Chaos appears!\n";
	mmsgout_arr[0] =
"Another violent burst of energy smashes the swirling\n"+
"mass of Chaos into nothing!\n";
	mmsgin_arr[1] =
"A Large furry Teddy bear suddenly appears in front of you!\n";
	mmsgout_arr[1] =
"A violent Femme jumps into the room and shreds the large furry\n"+
"teddy bear into shreds of cloth and stuffing!\n";
	mmsgin_arr[2] =
"You are shocked!\n";
	mmsgout_arr[2] =
"You are unshocked!\n";
	mmsgin_arr[3] =
"With the howling of a thousand discordant enegries,\n"+
"an Avatar of Chaos appears to do your bidding!\n";
	mmsgout_arr[3] =
"The Avatar of Chaos is summoned back by his creator\n";
	mmsgin_arr[4] =
"You fall to your knees in fear as the Chaos God appears before you!\n";
	mmsgout_arr[4] =
"You breath a sigh of relief as the Chaos God departs.\n";
  }

}

short() {
  int i;
  if(owner->query_invis()) return 0;
  i = random(10);
  if(short_arr)
    return short_arr[i];
  else
    return "Ted is the Avatar of Chaos!";
}

can_put_and_get() { return 0; }

long() {
  tell_object(owner, this_player()->query_name()+" looked at you.\n");
  write("\n\n-->God of Chaos!\n\n");
  if(this_player()->query_level() < APPRENTICE) {
    write("You are terrified of Teds power and run away!!!!!\n\n");
    this_player()->run_away();
  }
  return 1;
}

id(str, lvl) {
  if(owner->query_invis() >= NO_ID)
    return 0;
  return (str==owner->query_name() || str=="ted" || str=="chaos");
}

shout_to_all(str) {
  if(!str) { write("Shout what?\n"); return 0; }
  shout("Chaos screach's across the world and you are able to make out\n");
  shout(format("the words: "+str+"\n",78));
  write(format("You screach: "+str+"\n",78));
  return 1;
}

emote(str) {
  if(!str) { write("Emote what?\n"); return 0; }
  say("Chaos "+str+"\n");
  write("You "+str+"\n");
  return 1;
}
tell(str) {
	object          ob;
	string          who, it;
	string          msg;
	if(!str || sscanf(str, "%s %s",who,msg) != 2) { write("Tell what ?\n"); return 0; }
	it = lower_case(who);
	ob = find_living(it);
	if (!ob) { write("No player with that name.\n"); return 1; }
	tell_object(ob, "A small burst of chaos appears and screaches noisily!\n");
	tell_object(ob, format("It seems to tell you: "+msg+"\n",78));
        write(format("You tell "+who+": "+msg+"\n",78));
	return 1;
}
quit() {
	owner->save_me(0);
	owner->drop_all(1);
	shout("You feel less Chaotic!\n");
	write("Saving Ted\n");
	destruct(owner);
	return 1;
}
home() {
	if (owner->query_invis() < INVIS_ACTION)
	say("In a burst of violent energy, Chaos conforms itself to HOME!\n");
	move_object(owner, "players/ted/workroom");
	if (owner->query_invis() < INVIS_ACTION)
	say("A massive discharge of energy slowly forms to Chaos\n");
	call_other(owner, "look");
	return 1;
}
communicate(str) {
	string          verb;

	verb = query_verb();
	if (str == 0)
		str = "";
   if(verb[0] == "'")
		str = extract(verb, 1)  + str;
	say(format("A burst of Chaos says: "+str+"\n",78));
        write(format("You say: "+str+"\n",78));
	return 1;
}
move_player(dir_dest, optional_dest_ob) {
    string dir, dest;
    object ob;
    int     is_light, i, a;

    a = random(5);
    if(!optional_dest_ob) {
	if(sscanf(dir_dest, "%s#%s", dir, dest) != 2) {
	    tell_object(owner, "Move to bad dir/dest\n");
	    return;
	}
    } else {
	dir = dir_dest;
	dest = optional_dest_ob;
    }
	if(dir == "X" && !owner->query_invis()) {
		say(mmsgout_arr[a]);
	} else
		if(!owner->query_invis())
		    say("A gust of wind blows the mass of Chaos "+dir+"\n");
    move_object(owner, dest);
    if(!optional_dest_ob)
	tell_object(owner, "/" + dest + "\n");
	if(dir == "X" && !owner->query_invis())
		say(mmsgin_arr[a]);
	    else
		if(!owner->query_invis())
		    say("Chaos arrives.\n");
    ob = environment(owner);
    if(owner->query_brief())
	write(call_other(ob, "short", 0) + ".\n");
    else
	call_other(ob, "long", 0);
    for(i = 0, ob = first_inventory(ob); ob; ob = next_inventory(ob)) {
	if(ob != owner) {
	    string short_str;
	    short_str = call_other(ob, "short");
	    if(short_str)
		write(short_str + ".\n");
	}
	if(i++ > 40) {
	    write("*** TRUNCATED\n");
	    break;
	}
    }
}
teleport(dest) {
	object          ob;
	int		i;
	if (!dest) {
		write("Goto where ?\n");
		return 1;
	}
	ob = find_living(dest);
	i = random(5);
	if (ob) {
		ob = environment(ob);
		if (owner->query_invis() < INVIS_TELEPORT)
			say(mmsgout_arr[i]);
		move_object(owner, ob);
		if (owner->query_invis() < INVIS_TELEPORT)
			say(mmsgin_arr[i]);
		if (owner->query_brief())
			write(call_other(ob, "short", 0) + ".\n");
		else
			call_other(ob, "long", 0);
		ob = first_inventory(ob);
		while (ob) {
			if (ob != this_object()) {
				string          short_str;
				short_str = call_other(ob, "short");
				if (short_str)
					write(short_str + ".\n");
			}
			ob = next_inventory(ob);
		}
		return 1;
	}
	this_player()->teleport(dest);
	return 1;
}
