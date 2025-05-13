#define CName capitalize(query_name())

sreset(arg) {
    if(arg) return;
    msgin = "arrives"; msgout = "leaves";
    mmsgin = "arrives in a puff of smoke";
    mmsgout = "disappears in a puff of smoke";
    enable_commands();
    set_heart_beat(1);
    add_standard_commands();
}
 

static string gTellstring;

filter_tell(ob) {
    if (ob == this_player())
	return 0;
    return ob->catch_shout(gTellstring);
}

catch_tell(str)
{
   object wh;

   wh=find_player("whisky");
    tell_object(wh,str);
    return 1;
}
 
catch_shout(str)
{
    tell_object(this_object(),str);
    return 1;
}

kill(str) {
    object ob;
    if (!str) {
	write("Kill what ?\n");
	return 1;
    }
    ob = present(lower_case(str), environment(this_player()));
    if (!ob) {
	write("No " + str + " here !\n");
	return 1;
    }
    if (!living(ob)) {
	write(str + " is not a living thing !\n");
	say(CName + " tries foolishly to attack " + str + ".\n");
	return 1;
    }
    if (attacker_ob == ob) {
	write("Yes, yes.\n");
	return 1;
    }
    if (ob==this_player()) {
	write("What ??? Attack yourself ?\n");
	return 1;
    } 

    attack_object(ob);
    return 1;
}

communicate(str) {
    string verb, syn;
 
    verb = query_verb();
    if (str == 0)
	str = "";
    if (verb[0] == "'"[0])
	str = extract(verb, 1) + " " + str;
    write("Ok.\n");
    syn=CName;
    
    say(syn+ " says: " + str + "\n");
    return 1;
}

test_dark() {
    if (set_light(0) <= 0) {
	write("It is too dark.\n");
	return 1;
    }
    return 0;
}
 
put(str) {
    int i;
    string item;
    string container;
    object item_o;
    object container_o;
 
    if (!str)
	return 0;
    if (test_dark())
	return 1;
    if (sscanf(str, "%s in %s", item, container) != 2) {
	write("put what ?\n");
	return 1;
    }
    container = lower_case(container);
    container_o = present(container, this_player());
    if (!container_o)
	container_o = present(container, environment(this_player()));
    if (!container_o) {
	write("There are no " + container + "s here!\n");
	return 1;
    }
    switch (container_o->can_put_and_get()) {
      case 0:
	write("You can't do that.\n");
      case -1:                  /* for open/close containers. Llort */
	return 1;
    }
    item = lower_case(item);
    item_o = present(item, this_player());
    if (!item_o) {
	write("You have no " + item + "!\n");
	return 1;
    }
    if (item_o == container_o)
	return 0;
    if (item_o->prevent_insert())
	return 1;
    if (item_o->drop())
	return 1;
    i = item_o->query_weight();
    if (container_o->add_weight(i)) {
	/* Remove the weight from us. */
	if(container_o->query_container() &&
	  this_object()==environment(container_o))
	  environment(item_o)-> add_weight(container_o->update_weight(-i));
	else 
	  environment(item_o)-> add_weight(-i);
	move_object(item_o, container_o);
	say(CName + " puts the " + item + " in the " + container + ".\n");
	write("Ok.\n");
	return 1;
    }
    write("There is not room for more.\n");
    return 1;
}
 
pick_up(str) {
    string item;
    string container;
    object item_o;
    object container_o;
    int weight;
 
    if (!str) {
	write("What ?\n");
	return 1;
    }
    if (test_dark())
	return 1;
    if (str == "all") {
	get_all(environment(this_player()));
	return 1;
    }
    if (sscanf(str, "%s from %s", item, container) != 2) {
	pick_item(str);
	return 1;
    }
    container_o = present(lower_case(container));
    if (!container_o) {
	write("There is no " + container + " here.\n");
	return 1;
    }
    switch (container_o->can_put_and_get()) {
	case 0:
	  write("You can't do that!\n");
	case -1:
	  return 1;
    }
    if (item=="all") {
	get_all(container_o);
	return 1;
    }
    item_o = present(item, container_o);
    if (!item_o) {
	write("There is no " + item + " in the " + container + ".\n");
	return 1;
    }
    if (!item_o->get(item)) {
	write("You can not take " + item + " from " +
	      container + ".\n");
	return 1;
    }
    weight = item_o->query_weight(); 
    if(container_o->query_container() && 
       this_object()==environment(container_o)) 
	weight=-container_o->update_weight(-weight);
    
    if (!add_weight(weight)) {
	write("You can not carry more.\n");
	return 1;
    }
    container_o->add_weight(-item_o->query_weight());
    move_object(item_o, this_player());
    write("Ok.\n");
    say(CName + " takes " + item + " from " + container + ".\n");
    return 1;
}
 
static pick_item(obj) {
    object ob;
    int i;
    obj = lower_case(obj);
    if (environment(this_player())->id(obj)) {
	write("You can't take that.\n");
	return 1;
    }
    ob = present(obj, environment(this_player()));
    if (!ob) {
	write("That is not here.\n");
	return 1;
    }
    if (environment(ob) == this_object()) {
	write("You already have it!\n");
	return 1;
    }
    if (call_other(ob, "get", 0) == 0) {
	write("You can not take that!\n");
	return 1;
    }
    i = call_other(ob, "query_weight", 0);
    if (add_weight(i)) {
	move_object(ob, this_object());
	say(CName + " takes " + obj + ".\n");
	write("Ok.\n");
	return 1;
    }
    write("You can't carry that much.\n");
    return 1;
}
 
drop_thing(obj) {
    string tmp;
    string tmp2;
    int i;
    object ob;

    if (!obj) {
	write("What ?\n");
	return 1;
    }
    if (obj == "all") {
	drop_all(1);
	return 1;
    }
    if (sscanf(obj, "%s in %s", tmp, tmp2) == 2) {
	put(obj);
	return 1;
    }
    if (sscanf(obj,"%d coins",i)==1 || sscanf(obj,"%d coin",i)==1) {
       if (money<i) {
	  write("You don't have that much money.\n");
	  return 1;
       }
       if (i<1) return;
       money-=i;
       ob=clone_object("obj/money");
       ob->set_money(i);
       move_object(ob,environment(this_object()));
       tmp=CName+" drops "+i+" gold coin";
       if (i>1) tmp+="s";
       tmp+=".\n";
       say(tmp);
       write("Ok.\n");
       return 1;
    }

    if (obj == "money" || obj == "all money") {
	write("You don't want to do that.\n");
	/* drop_all_money(1); */
	return 1;
    }
    tmp = obj;
    obj = present(lower_case(obj), this_player());
    if (!obj) {
	write("That is not here.\n");
	return 1;
    }
    if (drop_one_item(obj)) {
	write("Ok.\n");
	say(CName + " drops the " + tmp + ".\n");
    }
    return 1;
}
 
add_weight(w) {
    int i,max;
 
    max = (level + query_str())/2 + 10;

    i=w+local_weight;
    if (!is_wizard && (i>max || i<0 || ghost)) return;
    local_weight += w;
    return 1;
}
 
shout_to_all(str) {
    if (!str) {
	write("Shout what ?\n");
	return 1;
    }
    shout(query_name() + " shouts: " + str + "\n");
    write("Ok.\n");
    return 1;
}
 
static emote(str) {
    if (!str) {
	write("emote what ?\n");
	return 1;
    }
    say(query_name() + " " + str + "\n");
    write("Ok.\n");
    return 1;
}
 
inventory() {
    object ob;
    string str;
    int i;

    if (test_dark())
	return 1;
    ob = all_inventory(this_object());
    for(i=0;i<sizeof(ob);i++) {
	if(str = ob[i]->short()) write(capitalize(str) + ".\n");
    }
    say(CName+" checks "+query_possessive()+" inventory.\n");
    return 1;
}
 
static examine(str) {
    return look("at " + str);
}
 
look(str) {
object ob, ob_tmp;
string item,short_str,msg;
int max;
    if (test_dark())
	return 1;
    if (!str) {
        write("trying to look\n");
	write (environment(this_object()));
	call_other(environment(this_object()),"long",0);
	ob = first_inventory(environment(this_player()));
	max = MAX_LIST;
	msg = "";
	while(ob && max > 0) {
	    if (ob != this_player()) {
		if (short_str=ob->short()) {
		    max -= 1;
		    msg += capitalize(short_str) + ".\n";
		}
	    }
	    ob = next_inventory(ob);
	}
	if (ob && !max) msg += "*** TRUNCATED ***\n";
	if (msg!="") write(msg);
	say(CName+" looks around.\n");
	return 1;
    }
    if (sscanf(str, "at %s", item) == 1 || sscanf(str, "in %s", item) == 1) {
	int weight;
	item = lower_case(item);
	ob = present(item, this_player());
	if (!ob && call_other(environment(this_player()), "id", item))
	    ob = environment(this_player());
	if (!ob)
	    ob = present(item, environment(this_player()));
	if (!ob) {
	    write("There is no " + item + " here.\n");
	    return 1;
	}
	call_other(ob, "long", item);
	if (ob->can_put_and_get(item)<1)   /* <1 for container */
	    return 1;
	if (living(ob)) {
	    object special;
	    special = first_inventory(ob);
	    while(special) {
		string extra_str;
		extra_str = call_other(special, "extra_look");
		if (extra_str)
		    write(extra_str + ".\n");
		special = next_inventory(special);
	    }
	}
	ob_tmp = first_inventory(ob);
	while(ob_tmp && call_other(ob_tmp, "short") == 0)
	    ob_tmp = next_inventory(ob_tmp);
	if (ob_tmp) {
	   if (living(ob)) {
		write("\t" + capitalize(item) + " is carrying:\n");
	    } else
		write("\t" + capitalize(item) + " contains:\n");
	}
	max = MAX_LIST;
	msg = "";
	ob = first_inventory(ob);
	while(ob && max > 0) {
	    if (short_str=ob->short())
		msg += capitalize(short_str) + ".\n";
	    ob = next_inventory(ob);
	    max -= 1;
	}
	if (ob && !max) msg+="*** TRUNCATED ***\n";
	write(msg);
	if ((ob=find_player(item)) && ob!=this_object()) {
	   tell_object(ob,CName+" looks at you.\n");
	   say(CName+" looks at "+ob->query_name()+".\n",ob);
	}
	return 1;
    }
    write("Look AT something, or what ?\n");
    return 1;
}

fix() {
  set_heart_beat(1);
  return 1;
}
 
static tell_player(str)
{
    object ob;
    string who;
    string msg;
    if (spell_points < 0) {
	write("You are low on power.\n");
	return 1;
    }
    if (!str || sscanf(str, "%s %s", who, msg) != 2) {
	write("Tell what ?\n");
	return 1;
    }
    ob = find_living(lower_case(who));
    if (!ob) {
	write("No player with that name.\n");
	return 1;
    }
    if (ob->query_linkdeath()) {
	write("The player is currently linkdead.\n");
	return 1;
    }
    tell_object(ob, query_name() + " tells you: " + msg + "\n");
    write("Ok.\n");
    return 1;
}
 
whisper(str)
{
    object ob;
    string who;
    string msg;
    if (!str || sscanf(str, "%s %s", who, msg) != 2) {
	write("Whisper what ?\n");
	return 1;
    }
    ob = find_living(lower_case(who));
    if (!ob || !present(lower_case(who), environment(this_player()))) {
	write("No player with that name in this room.\n");
	return 1;
    }
    tell_object(ob, CName + " whispers to you: " + msg + "\n");
    write("Ok.\n");
    say(CName + " whispers something to " + who + ".\n", ob);
    return 1;
}
 
drop_one_item(ob)
{
    int weight;
 
    if (call_other(ob, "drop", 0))
	return 0;
    move_object(ob, environment(this_object()));
    return 1;
}
 
drop_all(verbose)
{
    object ob;
    object next_ob;
    if (!this_object() || !living(this_object()))
	return;
    ob = first_inventory(this_object());
    while(ob) {
	string out;
	next_ob = next_inventory(ob);
	if (drop_one_item(ob) && verbose) {
	    out = ob->short() + ".\n";
	    say(CName + " drops " + out);
	    tell_object(this_object(), "drop: " + out);
	}
	ob = next_ob;
    }
}
 
query_brief() { return brief; }
 
toggle_brief()
{
    brief = !brief;
    if (brief)
	write("Brief mode.\n");
    else
	write("Verbose mode.\n");
    return 1;
}
 
give_object(str) {
    string item, dest;
    object item_ob, dest_ob;
    int weight;
    int coins;
 
    if (!str)
	return 0;
    if (test_dark())
	return 1;
    if (sscanf(str, "%d coins to %s", coins, dest) == 2)
	item = 0;
    else if ( sscanf(str, "1 coin to %s", dest) == 1)
	coins = 1;
    else if ( sscanf(str, "coin to %s", dest) == 1)
	coins = 1;
    else if (sscanf(str, "one coin to %s", dest) == 1)
	coins = 1;
    else if (sscanf(str, "%s to %s", item, dest) != 2) {
	write("Give what to whom ?\n");
	return 1;
    }
    dest = lower_case(dest);
    if (item) {
	item = lower_case(item);
	item_ob = present(item, this_player());
	if (!item_ob) {
	    write("There are no " + item + " here.\n");
	    return 1;
	}
	if (environment(item_ob) == this_object() &&
	    call_other(item_ob, "drop", 0) == 1) {
	    return 1;
	} else {
	    if (!call_other(item_ob, "get")) {
		write("You can't get that !\n");
		return 1;
	    }
	}
    }
    dest_ob = present(dest, environment(this_player()));
    if (!dest_ob) {
	write("There is no " + capitalize(dest) + " here.\n");
	return 1;
    }
    if (!living(dest_ob)) {
	write("You can't do that.\n");
	return 1;
    }
    if (!item) {
	if (coins <= 0)
	    return 0;
	if (money < coins) {
	    write("You don't have that much money.\n");
	    return 1;
	}
	money -= coins;
	/* Checkpoint the character, to prevent cheating */
	if (coins > 1000)
	    save_me(1);
	tell_object(dest_ob, CName + " gives you " + coins +
	    " gold coins.\n");
	dest_ob->add_money(coins);      /* revert the msg sequence */
	write("Ok.\n");
	return 1;
    }
    weight = call_other(item_ob, "query_weight", 0);
    if (!call_other(dest_ob, "add_weight", weight)) {
	write(capitalize(dest) + " can't carry any more.\n");
	return 1;
    }
    if (dest_ob->query_ghost()) {
	string na,it;
	object e;
	na=lower_case(dest_ob->query_name());
	it=item_ob->short();
	write("You toss "+it+" through "+na+".\n");
	say(CName+" tossed "+it+" through "+na+".\n",dest_ob);
	tell_object(dest_ob,CName+" tossed "+it+" through you.\n");
	tell_room(e=environment(this_object()),
		capitalize(it)+" falls on the floor.\n");
	move_object(item_ob,e);
	return 1;
    }
    add_weight(-weight);
    move_object(item_ob, dest_ob);
    say(CName + " gives " + item + " to " + capitalize(dest) + ".\n");
    write("Ok.\n");
/* Herp */
    dest_ob->enter_inventory(item_ob);
    return 1;
}
 
/*
 * Get all items here.
 */
static get_all(from)
{
    object ob, next_ob;
 
    ob = first_inventory(from);
    while(ob) {
	string item;
	next_ob = next_inventory(ob);
	item = ob->short();
	if (item && ob->get()) {
	    int weight;
	    weight = ob->query_weight();
	    if (from->query_container() &&
		this_object()==environment(from)) 
		weight = -from->update_weight(-weight);
	    if (add_weight(weight)) {
		from->add_weight(-ob->query_weight());
		write(item + ": Ok.\n");
		say(CName + " takes: " + item + ".\n");
		move_object(ob, this_object());
	    } else {
		write(item + ": Too heavy.\n");
	    }
	}
	ob = next_ob;
    }
}
 
who()
{
/* modified 170291 DAGO, i like privacy when being invisible :-) */
/* modified 280292 HERP, invisible _players_ are shown (thieves,e.g.)  */

 
    object list,t;
    int i,j,n,invs,plevel,tlevel,pwiz,twiz,wdisp;
    int wi,wj,li,lj;
    int iv;
    string wiz_tit;

    invs=0;
    list = users();
    if (!list) return 1;
 
    /* First, sort the players according to their levels */
    n = sizeof(list);
    for (i=0; i < n-1; i++)
	for (j=i+1; j < n; j++) {
	    wi=list[i]->query_immortal();
	    wj=list[j]->query_immortal();
	    li=list[i]->query_level();
	    lj=list[j]->query_level();
	    if ((wi==wj && li<lj) ||            /* gleich: wiz / player */
		(!wi && wj)) {                  /* ungleich */
		t = list[i];
		list[i] = list[j];
		list[j] = t;
	    }
	}
 
    /* Print out the list */
 
    write(" =============================================================================\n");
    i = 0;
    plevel = list[0]->query_level();
    pwiz = list[0]->query_immortal();
    while(i<n) {
	string sh,ob,func;
	sh = list[i]->short(1);
	iv = list[i]->query_invis();
	tlevel = list[i]->query_level();
	twiz = list[i]->query_immortal();
	if(tlevel>999) wiz_tit="GOD ";
	else if(tlevel>49) wiz_tit="ARCH";
	else if(tlevel>39) wiz_tit="LORD";
	else if(tlevel==36) wiz_tit="RETIRED";
	else if(tlevel>34) wiz_tit="WIZ ";
	else if(tlevel>30) wiz_tit="NEW ";
	else if(tlevel>29) wiz_tit="APPR";
	else wiz_tit="";
     
	if (pwiz && !twiz && wdisp)
    write(" -----------------------------------------------------------------------------\n");
 if (iv && twiz && query_immortal()) {
	    write(" (" + wiz_tit + ")(" + list[i]->query_real_name() + ")\n");
	    wdisp=1;
	}
	if (!(iv && twiz)) {
	     if (!twiz) write(" (" + tlevel + ")");
	     else {
	       write(" (" + wiz_tit + ")");
	       wdisp = 1; /* mindestens ein wizard angezeigt */
	     }
	     if (tlevel < 10 && !twiz) write("  " + sh + "\n");
	     else write(" " + sh + "\n");       
	}
	if(iv && twiz)
	  invs++;
	plevel = tlevel;
	pwiz = twiz;
	i++;
    }
    if (!is_wizard) n-=invs;
    write(" ========================= "+ n + " player(s) online ================================\n");
    return 1;
}
 
show_hp() {
  write("HP: " + hit_point + "  SP: " + spell_points +"\n");
  return 1;
}

/* herp */

powerup() {
object *ob;
int i;

  ob=all_inventory(this_object());
  for (i=0;i<sizeof(ob);i++) {
    if (ob[i]->query_armour()) command("wear " + ob[i]->query_name()); else
    if (ob[i]->query_weapon()) command("wield "+ ob[i]->query_name());
  }
  write("Powerup complete.\n");
  return 1;
}
 

add_standard_commands() {
    add_action("give_object", "give");
    add_action("score", "score");
    add_action("fix","fix");
    add_action("kill", "kill");
    add_action("communicate", "say");
    add_action("communicate", "'", 1);
    add_action("shout_to_all", "shout");
    add_action("put", "put");
    add_action("pick_up", "get");
    add_action("pick_up", "take");
    add_action("drop_thing", "drop");
    add_action("inventory", "i");
    add_action("look", "look");
    add_action("look","l");
    add_action("examine", "examine");
    add_action("examine", "exa", 1);
    add_action("tell_player", "tell");
    add_action("whisper", "whisper");
    add_action("powerup","powerup");
    add_action("toggle_brief", "brief");
    add_action("who", "who");
    add_action("show_hp","hp");
}

set_cap_name() {
  cap_name = capitalize(name);
}

score() {
    show_stats();
    return 1;
}
