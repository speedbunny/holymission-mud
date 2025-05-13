#define is_wiz (this_player()->query_wizard())

object mark;

init() {
    add_action("i_dump","i_dump");
    add_action("i_mark","i_mark");
    add_action("i_destruct","i_destruct");
    add_action("i_call","i_call");
    add_action("i_mark","im");
    add_action("ih","ih");
    add_action("i_destruct","id");
    add_action("i_call","ic");
    add_action("ii","ii");
    add_action("ir","ir");
    add_action("il","il");
    add_action("idl","idl");
    add_action("ime","ime");
}

query_auto_load() { return "obj/marker:normal"; }

get() { return 1; }

drop() { if (this_player()->query_wizard()) return 1; }

ih() { return i_mark("here"); }
ir(str) { if (!str) return i_call("reset"); else return i_call("reset 1"); }
ii() { return i_call("init"); }
il(str) { return i_mark("living "+str); }
ime() { return i_mark("living "+this_player()->query_real_name()); }
idl() { return i_dump("list"); }

i_dump(str) {
    int tmp;
    if (!is_wiz) return; 
    if (mark == 0) {
	write("Nothing marked.\n");
	return 1;
    }
    if (str == "list") {
	object ob;
	int i;
	ob = first_inventory(mark);
	while(ob) {
	    i += 1;
	    write(i + ":\t");
	    write(ob);
	    write("\t" + call_other(ob, "short") + "\n");
	    ob = next_inventory(ob);
	}
	return 1;
    }
    write(call_other(mark, "short"));
    if (living(mark))
	write("(living)\n");
    if (call_other(mark, "query_npc"))
	write("(NPC)");
    write("\n");
    tmp = call_other(mark, "query_value");
    if (tmp)
	write("Value:\t" + tmp + "\n");
    tmp = call_other(mark, "query_weight");
    if (tmp)
	write("Weight:\t" + tmp + "\n");
    return 1;
}

i_mark(str) {
    string tmp;

    if (!is_wiz) return;
    if (str == 0)
	return 0;
    if (sscanf(str, "living %s", tmp) == 1) {
	mark = find_living(tmp);
	if (!mark) {
	    write("No such living object.\n");
	    return 1;
	}
	write(mark); write("\n");
	return 1;
    }
    if (sscanf(str, "ob %s", tmp) == 1) {
	mark = find_object(tmp);
	if (!mark) {
	    write("No such object.\n");
	    return 1;
	}
	write(mark); write("\n");
	return 1;
    }
    if (str == "up") {
	if (mark == 0)
	    return 0;
	if (environment(mark) == 0)
	    return 0;
	mark = environment(mark);
	write(mark); write("\n");
	return 1;
    }
    if (str == "here") {
	mark = environment(this_player());
	write(mark); write("\n");
	return 1;
    }
    if (sscanf(str, "%d", tmp) == 1) {
	object ob;
	if (mark == 0)
	    return 0;
	ob = first_inventory(mark);
	while(tmp > 1) {
	    tmp -= 1;
	    if (ob == 0)
		return 0;
	    ob = next_inventory(ob);
	}
	if (ob == 0)
	    return 0;
	mark = ob;
	write(mark); write("\n");
	return 1;
    }
    return 0;
}

id(str) {
    return str == "marker";
}

short() {
    return "Lars marker object";
}

long() {
    write("Commands available:\n");
    if (!is_wiz) write("None.\n");
    else {
	write("i_mark living 'name'\n");
	write("i_mark ob 'object'\n");
    	write("i_mark here\n");
    	write("i_mark up\n");
    	write("i_dump list\n");
    	write("i_dump\n");
    	write("i_destruct\n");
    	write("i_call 'function'\n");
    	write("i_call 'function' 'argument'\n");
	write("Abbrevations:\n");
	write("im: i_mark, ih: i_mark here, ic: i_call, ir: i_call reset\n");
        write("id: i_destruct, il: i_mark living, idl: i_dump list\n");
	write("ii: i_call init, ime: i_mark living <this_player>\n");
    }
}

query_value() {
    return 10;
}

i_destruct() {
    object ob;
    if (!is_wiz) return; 
    if (!mark)
	return 0;
    ob = environment(mark);
    destruct(mark);
    write("Ok. New: "); write(ob); write("\n");
    mark = ob;
    return 1;
}

i_call(str) {
    string with, what;
    int iwhat;

    if (!is_wiz) return; 
    if (!str)
        return 0;
    if (!mark) {
	write("No object marked.\n");
	return 1;
    }
    if (sscanf(str, "%s %d", with, what) == 2)
        iwhat = 1;
    else if (sscanf(str, "%s %s", with, what) != 2) {
	if (sscanf(str, "%s", with) == 1)
	    iwhat = 0;
	else
	    return 0;
    }
    write("Got: "); write(call_other(mark, with, what)); write("\n");
    say(call_other(this_player(), "query_name") +
	" patched the internals of " + call_other(mark, "short") + ".\n");
    return 1;
}
