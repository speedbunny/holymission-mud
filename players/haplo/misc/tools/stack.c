#define OK printitem("TOS = ", 1, tos()); return 1
#define DEPTH 2
#define EXTERN "players/lila/extern"

inherit "players/lila/model/stack";

string name, alias;
int light_level;
object result;
object old_env;

reset(arg) {
    ::reset(arg);
    if (arg) return;
    name="A stack pointer";
    alias="stack";
}

set_name(arg) { name=arg; }
set_alias(arg) { alias=arg; }

init_arg(arg) {
    if (arg && sscanf(arg, "%s#%s", alias, name)!=2)
	name=arg;
}

query_auto_load() {
    return explode(file_name(this_object()), "#")[0]+":"+alias+"#"+name;
}

short() { return name; }
id(str) { return str==alias || str=="stack" || str=="pointer" || str==name; }
long() { write(name+".\n\"help "+alias+"\" for info.\n"); }

drop() { return query_verb()!="give"; }
get(str) {
    if (!str) return 1;
    return (present(str)==this_object());
}

init() {
    if(environment()!=this_player()) return 0;
    if(file_size("/players/"+this_player()->query_real_name())!=-2) return 0;
    add_action("help", "help");
    add_action("light", "light");
    add_action("push_living", "living");
    add_action("push_object", "object");
    add_action("push_object", "here");
    add_action("push_object", "sclone");
    add_action("push_object", "sload");
    add_action("dup", "dup");
    add_action("this", "this");
    add_action("my", "my");
    add_action("over", "over");
    add_action("swap", "swap");
    add_action("drops", "drop");
    add_action("move", "move");
    add_action("forget", "forget");
    add_action("make", "make");
    add_action("env", "env");
    add_action("inv", "inv");
    add_action("index", "index");
    add_action("call", "call");
    add_action("extern", "extern");
    add_action("push_result", "result");
    add_action("qs", "query");
    add_action("qs", "set");
    add_action("print", "dump");
    add_action("do_empty", "empty");
    add_action("toggle_short", "short");
}

help(str) {
    if (!str || present(str)!=this_object())
	return 0;
    write("Commands available:\n"
	+"    living [name], object <filename>, here, this [thing], my [thing]"
	+",\n    dup, over, swap, drop"
	+",\n    dump, empty, short"
	+",\n    env, inv, index <n>"
	+",\n    move, forget, make"
	+",\n    call [# of args on stack] <function> [arg], result"
	+",\n    query, set, extern"
	+"\nSee also /players/lila/HELPSTACK"
	+"\n");
    return 1;
}

light(str) {
    int new_level;
    if (!str)
	new_level=light_level+1;
    else if (str=="off")
	new_level = 0;
    else if (sscanf(str, "%d", new_level)!=1)
	return 0;
    set_light(new_level-light_level);
    light_level = new_level;
    return 1;
}

push_living(str) {
    object ob;
    if (!str) str=this_player()->query_real_name();
    ob=find_living(str);
    if (!ob) return 0;
    push(ob); OK; }

push_object(str) {
    object ob;
    if (!str && query_verb()=="sclone") {
        if (objectp(tos())) str=explode("/"+file_name(tos()), "#")[0];
    }
    if (str) {
	if (str[0]!='/')
	    str=this_player()->query_path()+"/"+str;
	if (query_verb()=="sclone")
	    ob=clone_object(str);
	else {
	    if (query_verb()=="sload")
	        call_other(str, "???");
	    ob=find_object(str);
	}
    }
    else ob=environment(this_player());
    if (!ob) return 0;
    push(ob); OK; }

my(str) {
    object ob;
    if (str) ob=present(str)||present(str, environment(environment()));
    else ob=this_object();
    if (!ob) return 0;
    push(ob); OK; }

this(str) {
    object ob;
    if (str) ob=present(str, environment(environment()))||present(str);
    else ob=this_object();
    if (!ob) return 0;
    push(ob); OK; }

dup() {
    if (empty()) return 0;
    push(tos()); OK; }

over(str) {
    object t, u;
    if (str || empty()) return 0;
    t=pop(); if (empty()) { push(t); return 0; }
    u=tos(); push(t); push(u); OK; }

swap(str) {
    object t, u;
    if (str || empty()) return 0;
    t=pop(); if (empty()) { push(t); return 0; }
    u=pop(); push(t); push(u); OK; }

drops(str) {
    if (str || empty()) return 0;
    pop(); if (empty()) write("(empty)\n"); else OK; }

do_empty(str) {
    if (str) return 0;
    while(!empty())
	pop();
    write("(empty)\n");
    return 1;
}

toggle_short() {
    string abled;
    disable_short= !disable_short;
    if (disable_short)
	    abled="dis";
    else    abled="en";
    write("Display of short descriptions "
	+abled+"abled.\n");
    return 1;
}

forget() {
    object ob, tmp;
    ob=tos();
    if (!objectp(ob)) return 0;
    if (living(ob) && !ob->query_npc()) {
	write("Better \"force "+ob->query_real_name()+" quit\" instead.\n");
	return 1;
    }
    destruct(ob);
    pop();
    if (empty()) write("(empty)\n"); else OK; }

move() {
    object ob, dest;
    if (empty()) return 0;
    dest=pop();
    if (empty() || !objectp(dest)) { push(dest); return 0; }
    ob=pop();
    if (!objectp(ob)) { push(ob); push(dest); return 0; }
    move_object(ob, dest);
    if (empty()) write("(empty)\n"); else OK; }

make() {
    object ob, filename, blueprint, new, env, tmp;
    if (empty()) return 0;
    ob=tos();
    if (stringp(ob)) ob=find_object(ob);
    if (!objectp(ob)) return 0;
    filename=file_name(ob);
    if (sscanf(filename, "%s#%s", blueprint, new)==2) {
	if (blueprint=="obj/player") {
	    write("Better \"force "+ob->query_real_name()+" quit\" instead.\n");
	    return 1;
	}
	if (tmp = find_object(blueprint))
	    destruct(tmp);
	new=clone_object(blueprint);
        env=environment(ob);
	if (env)
	    move_object(new, env);
	move_object(ob, new);
	pop();
	push(new);
	if (ob==this_object()) {
	    new->set_name(name);
	    new->set_alias(alias);
	    printitem("=> ", 1, new);
	    destruct(ob);
	    return 1;
	}
	destruct(ob);
	OK; } 
    if (any_players_in(ob))
	write("no make until all players leave "+filename+".\n");
    else {
	if (environment()==ob)
	    move_object(this_object(), this_player());
	if (filename=="room/void") {
	    move_object(this_player(), "room/church");
	    clean(ob);
	    move_object(this_player(), filename);
	    OK; }
	env=environment(this_player());
	move_object(this_player(), "room/void");
	clean(ob);
	destruct(ob);
	call_other(filename, "???");
	new=find_object(filename);
	pop();
	push(new);
	if (env)
	    move_object(this_player(), env);
	else
	    move_object(this_player(), filename);
	OK; }
    return 1;
}

static clean(room) {
    object ob;
    while(1) {
	ob=first_inventory(room);
	if (!ob) return;
	destruct(ob);
    }
}

static any_players_in(ob) {
    ob=first_inventory(ob);
    while(ob) {
	if (living(ob) && !(ob->query_npc()) && ob!=this_player())
	    return 1;
        ob=next_inventory(ob);
    }
    return 0;
}

env() {
    object ob;
    if (empty()) return 0;
    push(environment(pop())); OK; }

inv() {
    if (empty() || !objectp(tos())) return 0;
    push(all_inventory(pop()));
    OK; }

index(str) {
    int i;
    object new;
    if (empty()) return 0;
    if (!str || sscanf(str, "%d", i)!=1 || i<0)
	return 0;
    new=tos()[i];
    pop();
    push(new); OK; }

do_call(whob, str) { string fun, arg;
    if (sscanf(str, "%s %d", fun, arg)==2)
  result = call_other(whob, fun, arg);
    else if (sscanf(str, "%s %s", fun, arg)==2)
  result = call_other(whob, fun, arg);
    else result = call_other(whob, str);
    printitem("=> ", DEPTH, result);
}

call(str) { int m, n; string fun, arg;
    if (!str) return 0;
    if (empty()) return 0;
    if ((m=sscanf(str+" ", "%d %s %s ", n, fun, arg))>=2)
        if (n==1) { object ob;
            ob=pop();
            if (empty()) {push(ob); return 0;}
	    if (m==3)
      result = call_other(tos(), "_"+fun, ob, arg);
	    else    result = call_other(tos(), fun, ob);
	    printitem("=> ", DEPTH, result);
        } else return 0;
    else
	do_call(tos(), str);
    return 1; }

extern(str) { int m, n; string fun, arg;
    if (!str) return 0;
    if ((m=sscanf(str+" ", "%d %s %s ", n, fun, arg))>=2)
        if (n==1) {
	    if (empty()) return 0;
	    if (m==3)
      result = call_other(EXTERN, "_"+fun, pop(), arg);
	    else    result = call_other(EXTERN, "_"+fun, pop());
	    printitem("=> ", DEPTH, result);
        } else return 0;
    else
	do_call(EXTERN, "_"+str);
    return 1; }

qs(arg) {
    if (!arg) 
	return 0;
    return call(query_verb()+"_"+arg);
}

push_result() {
    push(result); OK; }

