/*  file: sys/poss.c

    This object is used to connect a person possessed by another person,
    to avoid destructing the possessed person. The possessor can also
    use this object to set the snoop hook, thus allowing the possessed
    person seeing everything the possessor is doing.

    (C) 1993 mud@mud.uni-linz.ac.at	Herp aka Herbert Rosmanith

*/

object po;		/* the possessor */
object pd;		/* the possesse */
string pd_name;		/* name of possesse */
int level;
int sil=0;		/* possesse silenced ? */

init() {
    add_action("do_return","return");
    add_action("do_silence","silence");
}

init_poss(object ob) {
    pd=ob;
    po=previous_object();
    level=ob->query_level()+1;		/* needed for snoop() */
    pd_name=pd->query_real_name();
    call_out("check_destruct",600);	/* check every 10 minutes */
}

check_possessor() {
    if (!(environment()) ||
	!(interactive(environment())) ) { /* we lost our possessor */
	if (interactive(this_object()))
	    tell_object(this_object(),"Your possessor vanished !\nOh no, you are destructed !\n");
	destruct(this_object());
    }
}

set_command_modifier() { set_modify_command(this_object()); }

modify_command(str) {
    check_possessor();
    if (!sil) tell_object(pd,"["+capitalize(pd_name)+"] "+str+"\n");
    else tell_object(this_object(),"You must not talk now.\n");
    return 1;
}

query_level() { return level; }

do_return() {
object tp;

    if (!po) {
	write("Oh no! You have lost your original body\nYou cannot return.\n");
	return 1;
    }
    if (interactive(this_object())) {
        tp=this_player();
        snoop(this_object());	/* stop snooping */
        exec(po,tp);		/* reconnect the possessor */
        exec(tp,this_object());	/* reconnect the possesse */
        tell_object(po,"You return to your original body.\n");
        tell_object(tp,"You can move again freely.\n");
        po->reconnect();
    }
    else exec(po,this_player());	/* possessing monsters or objects */
    destruct(this_object());
    return 1;
}

do_silence(str) {

    if (!str) {
	notify_fail("Silence whom ?\n");
	return 0;
    }

    if (str=="off") sil=0;
    else {
	if (str!=pd_name) {
	    notify_fail("You are not possessing "+str+".\n");
	    return 0;
	}
	sil=1;
    }
    if (sil) tell_object(this_object(),"You are forced to be silent now.\n");
    else tell_object(this_object(),"You are allowed to talk now.\n");
    write("Ok.\n");
    return 1;
} 
