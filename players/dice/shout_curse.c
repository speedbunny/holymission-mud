query_auto_load() {
    return "obj/shout_curse:"+find_call_out("finish_curse");
}

start(ob,time) {
    move_object(this_object(), ob);
    if(!time) time=3600;
    call_out("finish_curse",time,0);
    tell_object(ob, "You feel your throat swell up and your mouth slam shut.\n");
}

init_arg(str) {
    /* patched by James 5/24/93, string argument cannot be compared
       with an integer, or passed as an integer argument */

    int time;

    time = to_int(str);
    if(time>0) start(this_player(), time);
    else destruct(this_object());
}

finish_curse() {
    tell_object(environment(this_object()), "Your throat and mouth recover.\n");
    destruct(this_object());
}

drop() { return 1; }

init() {
    add_action("dsay", "deutsch");
    add_action("dsay", "de");
    add_action("dsay", "18");
    add_action("do_say", "shout");
    add_action("do_say","qshout");
    add_action("do_say","rt");
    add_action("do_say","raven tell");
    add_action("do_say","bellow");
    add_action("do_say","pose");
    add_action("do_say","fshout");
    add_action("do_say","brawl");
    add_action("do_say", "tell");
    add_action("do_say", "whisper");
    add_action("do_say", "say");
    add_action("do_say", "'", 1);
    add_action("rsay", "rsay");
    add_action("rsay", "`", 1);
    add_action("rsay", "rtell");
    add_action("rsay", "rshout");
}

extra_look() { return "This player has trouble speaking.\n";  }

dsay() {
    if(!present("ohrring", this_player())) return 0;
    return do_say();
}

rsay() {
    if(!present("revtalker", this_player())) return 0;
    return do_say();
}

do_say() {
    say(this_player()->query_name() + " says: arfle bargle gloop.\n"),
    write("You try to say something, but your mouth gets confused.\n");
    return 1;
}

// Mangla: added these for compat with qmunicator code.
int id(string str) {

    return str == "shcurse";
}

string query_name() {

    return "shcurse";
}
