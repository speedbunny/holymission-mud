/* Modified to be autoload */
/* Now also inherited from qtool so tyhat it can be hidden */
/*
 * This is a genereal purpose tool.
 * It can be used to find objects, list info about them,
 * and walk up and down the inventory lists.
 */
#define FILENAME "players/qclxxiv/misc/mytrace"	/* change if neccessary */

inherit "/players/qclxxiv/qtool";

int nja;
string vars;
object stores;
string query_list;

init() {
	::init();
    if (this_player() && this_player()->query_wizard()) {
	add_action("help", "help");
	add_action("Dump", "Dump");
	add_action("Destruct", "Destruct");
	add_action("Call", "Call");
	add_action("Tell", "Tell");
	add_action("Trans", "Trans");
	add_action("Set", "Set");
	add_action("Goto", "Goto");
	add_action("In", "In");
	add_action("Clean", "Clean");
	add_action("man", "man");
    }
}

query_auto_load() { return FILENAME+":"+nja; }

Dump(str) {
    int tmp, i;
    object ob;
    string flag, path;

    if (str == 0) {
	write("All variables:\n");
	while(i<sizeof(vars)) {
	    if (vars[i]) {
		write(vars[i] + ":\t");
		write(stores[i]);
		write("\n");
	    }
	    i += 1;
	}
	return 1;
    }
    if (sscanf(str, "%s %s", path, flag) != 2)
	path = str;
    ob = parse_list(path);
    if (ob == 0)
	return 0;
    if (flag == "list") {
	ob = first_inventory(ob);
	while(ob) {
	    i += 1;
	    write(i + ":\t");
	    write(ob);
	    write("\t" + call_other(ob, "short") + "\n");
	    ob = next_inventory(ob);
	}
	return 1;
    }
    write(ob); write(":\n");
    write(call_other(ob, "short"));
    if (living(ob))
	write("(living) ");
    if (tmp = query_ip_name(ob))
	write("(interactive) '" + query_ip_number(ob) + "' ");
    write("\n");
    if (tmp)
	write("query_idle:\t\t" + query_idle(ob) + "\n");
    tmp = creator(ob);
    if (tmp)
	write("Creator:\t\t" + tmp + "\n");
    tmp = query_snoop(ob);
    if (tmp)
	write("Snooped by " + tmp->query_real_name() + "\n");
    i = 0;
    while(i < sizeof(query_list)) {
	tmp = call_other(ob, query_list[i]);
	if (tmp) {
	    string t;
	    t = query_list[i] + ":";
	    if (strlen(t) < 8)
		t += "\t\t";
	    else if (strlen(t) < 16)
		t += "\t";
	    if (objectp(tmp))
		tmp = file_name(tmp);
	    else if (pointerp(tmp))
		tmp = "<ARRAY>";
	    write(t + "\t" + tmp + "\n");
	}
	i += 1;
    }
    return 1;
}

long() {
    write("Genral purpose object information retriever.\n");
    write("Do 'help tracer' for more information.\n");
}


get() {
    if (this_player() && !this_player()->query_wizard())
	call_out("self_destruct", 2);
    return 1;
}

query_value() {
    return 10;
}

Destruct(str) {
    object ob;
    ob = parse_list(str);
    if (!ob)
	return 0;
    destruct(ob);
    write("Ok.\n");
    return 1;
}

Call(str) {
    string with, what, item;
    int iwhat;
    object ob;
    int ret;

    if (!str)
        return 0;
    if (sscanf(str, "%s %s %d", item, with, what) == 3)
        iwhat = 1;
    else if (sscanf(str, "%s %s %s", item, with, what) != 3) {
	if (sscanf(str, "%s %s", item, with) == 2)
	    iwhat = 0;
	else
	    return 0;
    }
    ob = parse_list(item);
    if (!ob)
	return 0;
    ret = call_other(ob, with, what);
    if (intp(ret))
	write("Got int " + ret + "\n");
    else if (pointerp(ret))
	write("Array of size " + sizeof(ret) + "\n");
    else if (stringp(ret))
	write("String: '" + ret + "'\n");
    else if (objectp(ret)) {
	write("Object: "); write(ret);
	write("\n");
    }
    assign("ret", ret);
    say(call_other(this_player(), "query_name") +
	" patched the internals of " + call_other(ob, "short") + ".\n");
    return 1;
}

Tell(str) {
    string item, what;
    object ob;
    if (!str)
	return 0;
    if (sscanf(str, "%s %s", item, what) != 2)
	return 0;
    ob = parse_list(item);
    if (!ob)
	return 0;
    if (!living(ob)) {
	write("Not a living object.\n");
	return 1;
    }
    tell_object(ob, call_other(this_player(), "query_name") +
		" tells you: " + what + "\n");
    return 1;
}

Clean(str) {
    object ob, o, n;

    if (!str)
	return 0;
    ob = parse_list(str);
    if (!ob)
	return 0;
    for (n = first_inventory(ob); n; n = o) {
	o = next_inventory(n);
	if (query_ip_number(n))
	    continue;
	destruct(n);
    }
    write("Ok.\n");
    return 1;
}

Trans(str) {
    object mark;

    if (!str)
	return 0;
    mark = parse_list(str);
    if (!mark)
	return 0;
    if (call_other(mark, "get")) {
	if (transfer(mark, this_player()) != 0) {
	    write("Failure.\n");
	    return 1;
	}
    } else {
	move_object(mark, environment(this_player()));
    }
    write("Ok.\n");
    return 1;
}

static find_item(prev, str) {
    object ob;
    string tmp;

    if (str == "here")
	return environment(this_player());
    if (str == "^")
	return environment(prev);
    if (sscanf(str, "@%s", tmp) == 1)
	return find_living(tmp);
    if (sscanf(str, "*%s", tmp) == 1)
	return find_player(tmp);
    if (sscanf(str, "/%s", tmp) == 1) {
	call_other(tmp, "??");	/* Force load */
        return find_object(tmp);
    }
    if (sscanf(str, "$%d", tmp) == 1) {
	object u;
	u = users();
	write("size: " + sizeof(u) + "\n");
	if (tmp >= sizeof(u) || tmp < 0)
	    return 0;
	return u[tmp - 1];
    }
    if (sscanf(str, "$%s", tmp) == 1) {
	int i;
	while(i<sizeof(vars)) {
	    if (tmp == vars[i])
		return stores[i];
	    i += 1;
	}
	return 0;
    }
    if (prev == 0)
	prev = environment(this_player());
    if (sscanf(str, "\"%s\"", tmp) == 1) {
	ob = first_inventory(prev);
	while(ob && call_other(ob, "short") != tmp) {
	    ob = next_inventory(ob);
	}
	return ob;
    }
    if (sscanf(str, "#%d", tmp) == 1) {
	if (prev == 0)
	    return 0;
	ob = first_inventory(prev);
	while(tmp > 1) {
	    tmp -= 1;
	    if (ob == 0)
		return 0;
	    ob = next_inventory(ob);
	}
	return ob;
    }
    return present(str, prev);
}

parse_list(str) {
    string tmp, rest;
    object prev;

    prev = environment(this_player());
    while(prev && str) {
	if (sscanf(str, "%s:%s", tmp, rest) == 2) {
	    prev = find_item(prev, tmp);
	    str = rest;
	    /* disp(prev); */
	    continue;
	}
	prev = find_item(prev, str);
	/* disp(prev); */
	break;
    }
    assign("$", prev);
    if (objectp(prev))
	disp(prev);
    return prev;
}

static disp(ob) {
    write(file_name(ob) + "\n");
}

Set(str) {
    object ob;
    string item, var;

    if (!str)
	return 0;
    if (sscanf(str, "%s %s", var, item) != 2)
	return 0;
    ob = parse_list(item);
    if (!ob)
	return 0;
    assign(var, ob);
    return 1;
}

assign(var, val) {
    int i;

    while(i<sizeof(vars)) {
	if (vars[i] == var) {
	    stores[i] = val;
	    return;
	}
	if (vars[i] == 0) {
	    vars[i] = var;
	    stores[i] = val;
	    return;
	}
	i += 1;
    }
}

reset(arg) {
    if (arg)
	return;
    vars = allocate(5);
    stores = allocate(5);
    query_list = init_query();
	set_name("tracer");
	set_alias("trace");
    set_short("General purpose object tracer (modified)");
	hidden = 1;
}

Goto(str) {
    object mark;

    if (!str)
	return 0;
    mark = parse_list(str);
    if (!mark)
	return 0;
    say(this_player()->query_name() + " " + this_player()->query_mmsgout() +
	".\n");
    move_object(this_player(), mark);
    say(this_player()->query_name() + " " + this_player()->query_mmsgin() +
	".\n");
    write("Ok.\n");
    return 1;
}

/*
 * This will not work because command() only works for command_giver.
 */
in(str) {
    object mark, here;
    string path, cmd;

    if (!str)
	return 0;
    if (sscanf(str, "%s %s", path, cmd) != 2)
	return 0;
    mark = parse_list(path);
    if (!mark)
	return 0;
    here = environment(this_player());
    move_object(this_player(), mark);
    command(cmd);
    move_object(this_player(), here);
    write("Ok.\n");
    return 1;
}

/*
 * This function will be called by all clones.
 */
init_query() {
    if (query_list)
	return query_list;
    query_list = ({
	"query_ac", "query_alignment",
	"query_attack", "query_auto_load", "query_code", "query_create_room",
	"query_dir", "query_exp", "query_frog", "query_ghost",
	"query_hit_point", "query_hp", "query_info", "query_intoxination",
	"query_level", "query_listening", "query_max_weight", "query_money",
	"query_name", "query_npc", "query_race", "query_real_name",
	"query_spell_points", "query_soaked", "query_stuffed",
	"query_title", "query_type", "query_value",
	"query_wc", "query_weight", "query_wimpy", "query_worn",
	"weapon_class", "armour_class", "query_age", "query_gender_string",
	"query_str", "query_dex", "query_con", "query_int"
    });
    return query_list;
}

In(str) {
    string path, cmd;
    object ob, old_ob;
    if (!str)
	return 0;
    if (sscanf(str, "%s %s", path, cmd) != 2)
	return 0;
    ob = parse_list(path);
    if (!ob)
	return 0;
    old_ob = environment(this_player());
    move_object(this_player(), ob);
    command(cmd, this_player());
    move_object(this_player(), old_ob);
    return 1;
}

self_destruct() {
    tell_object(environment(this_object()),
		"The tracer object suddenly gets warm.\n");
    call_out("self_destruct2", 2);
}

self_destruct2() {
    tell_object(environment(this_object()),
		"The tracer object dissapear in a flash of light.\n");
    destruct(this_object());
}

help(str) {
    if (str == "tracer") {
	write("Do 'help tracer item' for information what an item can be.\n");
	write("Commands available:\n\n");
	write("Goto 'item'\n");
	write("Dump 'item' list\n");
	write("Dump 'item'\n");
	write("Destruct 'item'\n");
	write("Call 'item' 'function'\n");
	write("Call 'item' 'function' 'argument'\n");
	write("Tell 'item' 'str'\n");
	write("Trans 'item'\n");
	write("Set var 'item'\n");
	write("In 'item' command\n");
	write("Clean 'item'\n");
	write("man <topic>\n");
	return 1;
    }
    if (str == "tracer item") {
	write("An item is a list separated by ':'. An item in that list can be\n");
	write("@name\tName of a player or monster.\n");
	write("*name\tName of player only. Can be invisible.\n");
	write("\"str\"\tShort description of an item.\n");
	write("/obj\tName of an object or room.\n");
	write("$var\tContents of a variable. ($$ will give last object used)\n");
	write("$num\tPlayer number 'num'.\n");
	write("here\tThis room.\n");
	write("#num\tObject number 'num'.\n");
	write("id\tName of an item.\n");
	return 1;
    }
    return 0;
}

man(str) {
    int i;
    string manuals;

    manuals = ({ "/doc", "/doc/efun", "/doc/lfun", "/doc/helpdir",
		 "/doc/build", "/doc/w", "/doc/LPC" });
    if (str == 0) {
	write("Topics:\n");
	while (i < sizeof(manuals)) {
	    write(manuals[i] + " ");
	    i += 1;
	}
	write("\n");
	return 1;
    }
    str = "/" + str;
    while(i < sizeof(manuals)) {
	if (file_size(manuals[i] + str) == -2) {
	    write("Sub topics " + manuals[i] + str + ":\n");
	    ls(manuals[i] + str);
	    return 1;
	}
	if (file_size(manuals[i] + str) > 0) {
	    write(manuals[i] + str + ":\n");
	    this_player()->more(manuals[i] + str);
	    return 1;
	}
	i += 1;
    }
    write("Not found.\n");
    return 1;
}

drop()
{
	/* Can't be dropped. Disappears at quit */
	return 1;
}
