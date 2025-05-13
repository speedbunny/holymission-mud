inherit "/obj/treasure";

#define MAXUSERS 80

int get() {
    return 1;
}

int drop() {
    return 0;
}
 
void reset(int arg) {
    if (arg) 
        return;
    set_id("megaphone");
    set_weight(0);
    set_value(0);
    set_short("Megaphone");
    set_long("This is megaphone. "
        "Try 'megashout', 'megaxshout', 'megasay' or 'megatell'.\n");
}


void doit(string str,int maxlevel)
{
    object *u;
    int i;
    if (!str) {
        write("Not enough arguments, sorry.\n");
        return;
    }        
    u = users();
    for (i=0; i < sizeof(u) ; i++) {
        if (u[i]->query_level() <= maxlevel) 
            tell_object(u[i], str+"\n");
    }
    write("You megashout("+maxlevel+"): "+str+"\n");    
    return;
}

void init() {
    ::init();
    add_action("megashout","megashout");
    add_action("megaxshout","megaxshout");
    add_action("megatell","megatell");
    add_action("megasay","megasay");
}

int megashout(string str) {
    doit(str, 29);
    return 1;
}

int megaxshout(string str) {
    string tmp;
    int level;
    if (!str || sscanf(str, "%d %s", level, tmp) != 2) {
        write("Usage: megaxshout <level> <string>\n");
        return 1;
    }            
    doit(tmp, level);
    return 1;
}

int megatell(string str) {
    string target, mesg;
    object pl;
    if (!str || sscanf(str, "%s %s", target, mesg) != 2) {
        write("Usage: megatell <player> <msg>\n");   
        return 1;
    }
    target = lower_case(target);
    pl = find_player(target);
    if (!pl) {
        write("Cannot find "+capitalize(target)+".\n");   
        return 1;
    }
    tell_object(pl, mesg + "\n");
    write("You tell "+capitalize(target)+": "+mesg+"\n");
    return 1;
}

int megasay(string str) {
    say(str);
    write("You megasay: "+str+"\n");
    return 1;
}
