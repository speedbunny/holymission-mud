
#define RELIGION "Crom"
#define MIN_LEVEL 5
#define RINGTEST "players/moonchild/wedding/replace_it"
#define tr(str)\
  tell_room(environment(this_object()),"Barbarian Chief says: " + str + "\n")

inherit "obj/monster";

string one,two,genders,function,type,match,married_by;
object pone,ptwo;
int marrying,money_needed;

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Barbarian Chief");
    set_alias("chief");
    set_alt_name("priest");
    set_race("Crom");
    set_gender(1);
    set_short("Barbarian Chief");
    set_long("This is the chief barbarian for the whole horde. He is very\n"+
      "old and wise in his ways with his tales of Crom and past barbarian\n"+
      "victories. The chief mainly watches over the camp and teaches others\n"+
      "about Crom. He also performs the wedding services now for Barbarians\n"+
      "and their wife to be.  But the chief doesn't keep alive by doing his\n"+
      "services for free. Type 'weddinghelp' for futher details and instructions.\n");
    set_level(100);
    set_wc(50);
    set_whimpy(-1);
    set_hp();
    set_ep(1);
    set_trapped(1);
    money_needed=6000;
    genders=({ "creature", "husband", "wife" });
    setup_arrays();
    set_match(this_object(),function,type,match);
}

init() {
    ::init();
    add_action("set_hp", "set_hp");
    add_action("weddinghelp", "weddinghelp");
    add_action("weddinglist", "weddinglist");
    add_action("marry", "marry");
}

set_hp() { hit_point = 100000; max_hp = 100000; }

weddinghelp() {
    cat("/players/apollo/guild/TEXT/wedding_help");
    return 1;
}

weddinglist() {
    this_player()->more("/players/moonchild/wedding/WEDDINGS");
    return 1;
}


marry(str) {
    int belief;

    if(this_player()->query_level() < 31) {
	write("You have to be a Wizard to initiate a marriage.\n");
	return 1;
    }
    if(money_needed>0) {
	write("Barbarian Chief still needs paid " + money_needed + " coins.\n");
	return 1;
    }
    if(marrying) {
	write("Barbarian Chief is already marrying " + capitalize(one) + " and " + capitalize(two) + ".\n");
	return 1;
    }
    if(sscanf(str,"%s and %s", one, two) != 2) {
	write("Marry who?\n");
	return 1;
    }
    pone=present(one,environment(this_object()));
    if(!pone) {
	write("No " + capitalize(one) + " here!\n");
	return 1;
    }
    if(!living(pone)) {
	write("Don't be silly.\n");
	return 1;
    }
    if(pone->query_npc()) {
	write("Oh, very funny!\n");
	return 1;
    }
    if(RINGTEST->get_spouse(capitalize(one))) {
	write("But " + capitalize(one) + " is already married.\n");
	return 1;
    }
    ptwo=present(two,environment(this_object()));
    if(!ptwo) {
	write("No " + capitalize(two) + " here!\n");
	return 1;
    }
    if(!living(ptwo)) {
	write("Don't be silly.\n");
	return 1;
    }
    if(ptwo->query_npc()) {
	write("Oh, very funny!\n");
	return 1;
    }
    if(RINGTEST->get_spouse(capitalize(two))) {
	write("But " + capitalize(two) + " is already married.\n");
	return 1;
    }
#if 0
    if(pone->query_gender() == ptwo->query_gender()) {
	write("We do not allow homosexual marriages in the guild !");
	return 1;
    }
#endif
    /* Changed by Cashimor: Only people of the same religion can be married, and
       it has to be the religion that the priest has. 100293 */
    belief=pone->query_religion();
    if((!belief)||(belief!=RELIGION)) {
	write(pone->query_name()+" isn't a follower of "+RELIGION+"!\n");
	return 1;
    }
    belief=ptwo->query_religion();
    if((!belief)||(belief!=RELIGION)) {
	write(ptwo->query_name()+" isn't a follower of "+RELIGION+"!\n");
	return 1;
    }
    /* Changed by Cashimor: Only people that have a level of MINLEVEL and higher
       can be married. 240293 */
    if(pone->query_level()<MIN_LEVEL) {
	write(pone->query_name()+"'s level is too low.\n");
	return 1;
    }
    if(ptwo->query_level()<MIN_LEVEL) {
	write(ptwo->query_name()+"'s level is too low.\n");
	return 1;
    }
    marrying=1;
    married_by=capitalize(this_player()->query_real_name());
    tr("We are gathered here today");
    call_out("blah1",2,0);
    return 1;
}

blah1() {
    tr("To celebrate the joining of these two");
    call_out("blah2",2,0);
}

blah2() {
    tr(RELIGION+"-fearing people in holy matrimony.");
    call_out("blah3",2,0);
}

blah3() {
    tr("As far as I can see, there is no reason");
    call_out("blah4",2,0);
}

blah4() {
    tr("not to marry this couple. If there is");
    call_out("blah5",2,0);
}

blah5() {
    tr("anyone who knows any just cause or impediment");
    call_out("blah6",2,0);
}

blah6() {
    tr("as to why these two people should not be");
    call_out("blah7",2,0);
}

blah7() {
    tr("joined in holy matrimony let him speak now");
    call_out("blah8",2,0);
}

blah8() {
    tr("or forever hold his peace.");
    marrying=2;
    call_out("blah9",10,0);
}

blah9() {
    if(marrying==-1) {
	tr("It seems that a reason has been found.");
	tr("Therefore I suggest that these problems");
	tr("be sorted out before a new wedding is");
	tr("attempted.\n");
	return marrying=0;
    }
    tr("Do you, " + capitalize(one) + ", take this " + capitalize(two));
    tr("to be your lawful wedded mud-" + genders[ptwo->query_gender()] + ".");
    tell_object(pone,"Chief tells you: A simple yes or no will suffice.\n");
    marrying=3;
    call_out("blah10",1,0);
}

blah10() {
    if(marrying==3) call_out("blah10",1,0);
    if(marrying==-1) {
	tr("Well that suggests that the marriage is abandoned.");
	return marrying=0;
    }
    if(marrying==4) blah11();
}

blah11() {
    tr("Do you, " + capitalize(two) + ", take this " + capitalize(one));
    tr("to be your lawful wedded mud-" + genders[pone->query_gender()] + ".");
    tell_object(ptwo,"Chief tells you: A simple yes or no will suffice.\n");
    call_out("blah12",1,0);
}

blah12() {
    if(marrying==4) call_out("blah12",1,0);
    if(marrying==-1) {
	tr("Well that suggests that the marriage is abandoned.");
	return marrying=0;
    }
    if(marrying==5) blah13();
}

blah13() {
    object hubby,ring;
    if(pone->query_gender()==2) hubby=two;
    else if(!pone->query_gender()) hubby=two;
    else hubby=one;
    tr("Very well, " + capitalize(hubby) + ", you may kiss the bride.");
    money_needed=5000;
    write_file("/players/moonchild/wedding/WEDDINGS",
      ctime(time()) + ": " + capitalize(one) + " & " +
      capitalize(two) + ": Married by " + married_by + ".\n");
    say("Barbarian Chief gives ring to " + capitalize(one) + ".\n",pone);
    tell_object(pone,"Barbarian Chief gives ring to you.\n");
    move_object(ring=clone_object("players/moonchild/wedding/ring"),pone);
    ring->name1(capitalize(two));
    ring->name2(capitalize(one));
    ring->title_set();
    say("Barbarian Chief gives ring to " + capitalize(two) + ".\n",ptwo);
    tell_object(ptwo,"Barbarian Chief gives ring to you.\n");
    move_object(ring=clone_object("players/moonchild/wedding/ring"),ptwo);
    ring->name1(capitalize(one));
    ring->name2(capitalize(two));
    ring->title_set();
    marrying=0;
}

handle_say(str) {
    string who,what;
    if(sscanf(str,"%s says: %s\n",who,what)!=2 &&
      sscanf(str,"%s tells you: %s\n",who,what)!=2) return;
    if(who=="Barbarian Chief") return;
    if(marrying==2) return marrying=-1;
    what="." + lower_case(what) + ".";
    if(sscanf(what,"%sno%s",str) && (marrying==3 || marrying==4)) return marrying=-1;
    if(sscanf(what,"%syes%s",str) && (marrying==3 || marrying==4)) return marrying++;
}

setup_arrays() {
    function=({ "handle_say", 0 });
    type=({ "says", "tells you:" });
    match=({ "", " " });
}

add_money(m) {
    if(this_player()->query_immortal()) {
	write("Barbarian Chief tells you: I do not accept wizards' money!\n");
	return 1;
    }
    money_needed-=m;
    if(money_needed>0) write("Barbarian Chief tells you: I still need paid "
	  + money_needed + " coins.\n");
    else write("Barbarian Chief tells you: The wedding may now go ahead.\n");
}
