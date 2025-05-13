#include "lw.h"

inherit "obj/armour";

string name1,name2;

reset(arg) {
    ::reset();
    if(arg) return;
    set_name("ring");
    set_alias("wedding ring");
    set_short("A white gold wedding ring");
    set_type("wedding_ring");
}

init() {
    ::init();
    add_action("ring", "ring");
    add_action("ring", "ringem");
    add_action("ring", "rem");
    add_action("fiddle", "fiddle");
    add_action("correct", "correct");
    add_action("ringhelp", "ringhelp");
}

notify(p,str) { tell_object(p,lw(str)); write(lw(str)); }

ringhelp() {
    write("Use \"ring <message>\" to say a message to your spouse.\n"
      + "Use \"ringem <message>\" or just \"rem\" to send an emote message to them.\n"
      + "Use \"fiddle ring\" to fiddle with your wedding ring.\n"
      + "If you want to correct your title, use \"correct title\".\n");
    return 1;
}

ring(str) {
    object p;
    if(!str) return;
    p=find_player(lower_case(name1));
    if(!p) {
	write(name1 + " is not logged on.\n");
	return 1;
    }
    if(!interactive(p)) {
	write(name1 + " is linkdead.\n");
	return 1;
    }
    if(query_verb()=="ring") notify(p,"[*] " + name2 + " says: " + str + "\n");
    else notify(p,"[*] " + name2 + " " + str + "\n");
    return 1;
}

fiddle(str) {
    if(!id(str)) return;
    write("You fiddle with your wedding ring.\n");
    say(this_player()->query_name() + " fiddles with "
      + this_player()->query_possessive() + " wedding ring.\n");
    return 1;
}

start() {
    object p;
    write("Type \"ringhelp\" for use of your wedding ring.\n");
    wear("wedding ring");
    p=find_player(lower_case(name1));
    if(p) {
	tell_object(p, "[*] " + name2 + " enters the game.\n");
	write("[*] " + name1 + " is currently logged on.\n");
    }
    if(!this_player()->query_immortal()) title_set();
}

correct(str) {
    if(str!="title") return;
    title_set();
    write("Your title has been corrected.\n");
    return 1;
}

title_set() {
    object p;
    p=environment(this_object());
    if(!p) return;
    p->set_title("loves " + name1 + " very much");
    p->set_pretitle("none");
}

remove() {
    write("Why would you want to remove your wedding ring?\n");
    return 1;
}

long() {
    write("A beautiful white gold wedding ring, in the shape of two roses entertwined.\n"
      + "The inscription reads: " + name1 + " and " + name2 + " - In love forever.\n");
}

extra_look() { write(name2 + " is very happily married to " + name1 + ".\n"); }

query_weight() { return 0; }

name1(str) { name1=str; }

name2(str) { name2=str; }

query_spouse() { return name1; }

query_auto_load() { return "players/moonchild/wedding/ring:"; }

init_arg(str) {
    string me,them,junk;
    string *list;
    status f;
    int l;
    me=capitalize(this_player()->query_real_name());
    list = explode(read_file("/players/colossus/TESTLOG")+"\n", "\n");
    l=0;
    f=0;
    while(l<sizeof(list) && !f) {
	if(sscanf(list[l],"%s: " + me + " & %s: %s",junk,them,junk)==3) f=1;
	else if(sscanf(list[l],"%s: %s & " + me + ": %s",junk,them,junk)==3) f=1;
	l++;
    }
    if(!them) call_out("dest",1,0);
    else {
	name1=them;
	name2=me;
	call_out("start",2,0);
    }
}

dest() { destruct(this_object()); }

drop() {
    if(query_verb()=="sell") {
	write("Sell your wedding ring? Never!\n");
	return 1;
    }
    else if(query_verb()=="give") {
	write("Give your wedding ring away? Never!\n");
	return 1;
    }
    else if(query_verb()=="quit") {
	object ob;
	if(ob=find_player(lower_case(name1)))
	    tell_object(ob, "[*] " + name2 + " leaves you all alone.\n");
    }
    else write("Drop your wedding ring? Never!\n");
    return 1;
}
