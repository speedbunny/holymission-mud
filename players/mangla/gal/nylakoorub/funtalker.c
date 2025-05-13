/* Fun Talker...... */

#include "/obj/lw.h"


int id(string str) {
    return str=="talker" || str=="funtalker" ||
    str=="ft";
}

int get() { return 1; }
int drop() {
    destruct(this_object());
    return 1;
}


string short() {
    return "Torch";
}

void long() {
    write("This is the fun talker for all lines.\n"+
      "Commands are:\n"+
      "sayfun <echo name> <message>\n"+
      "tellfun <echo name> <to> <message>\n"+
      "shoutfun <message>\n"+
      "wizfun <first name> <second name(optional)> says <message>\n"+
      "wizfun/ <first name> <last name(optional)> * <message>\n"+
      "Note: first and last name will be automatically Capitalized.\n"+
      "      To not have a last name use a ! in place of a\n"+
      "      last name.\n"+
      "\n");

}

void init() {
    add_action("fun_say","sayfun");
    add_action("fun_tell","tellfun");
    add_action("fun_shout","shoutfun");
    add_action("fun_wiz","wizfun");
    add_action("fun_wiz","wizfun/");
}



fun_wiz(arg) {
    string who, last, message;
    if(query_verb()=="wizfun/") {
	sscanf(arg, "%s %s * %s", who, last, message);
	if(!last) {
	    "sys/chatd.c"->do_chat(-1, lw(
		"[wiz] "+capitalize(who)+
		" "+
		message+
		"\n"));
	    return 1;
	}
	else {
	    "sys/chatd.c"->do_chat(-1, lw(
		"[wiz] "+capitalize(who)+
		" "+
		capitalize(last)+
		" "+message+
		"/n"));
	    return 1;
	}
    }
    else {
	sscanf(arg, "%s %s says %s", who, last, message);
	if(last=="!") {
	    "sys/chatd.c"->do_chat(-1, lw(
		"[wiz] "+capitalize(who)+
		" says: "+
		message+
		"\n"));
	    return 1;
	}
	else {
	    "sys/chatd.c"->do_chat(-1,lw(
		"[wiz] "+capitalize(who)+
		" "+capitalize(last)+
		" says: "+message+
		"\n"));
	    return 1;
	}

    }
}

fun_say(arg) {
    string who,message;
    sscanf(arg, "%s %s", who, message);
    say(capitalize(who)+" says: "+message+"\n");
    write(capitalize(who)+" says: "+message+"\n");
    return 1;
}

fun_tell(arg) {
    string who,to,message;
    object pl_obj;
    sscanf(arg, "%s %s %s", who, to, message);
    pl_obj = find_living(to);
    if(!pl_obj) {
	write("That player is not on.\n");
	return 1;
    }
    tell_object(pl_obj, capitalize(who)+
      " tells you: "+message+"\n");
    write("You fun tell to "+capitalize(to)+" : "+
      "\n"+"'"+capitalize(who)+" tells you: "+
      message+"\n");
    return 1;
}


fun_shout(str) {
    write("You echo all: '" + str + "'\n");
    shout(str + "\n");
    return 1;
}

