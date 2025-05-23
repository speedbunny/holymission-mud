int new_object;
int new_value;
string new_short, new_long, new_name;

short()
{
    if (new_object)
	return new_short;
    return "The wand of creation";
}

query_value()
{
    if (new_object)
	return new_value;
    return 0;
}

long()
{
    if (new_object) {
	write(new_long + "\n");
	return;
    }
    write("It is a long and worn wand.\n");
    write("It originally belonged to Lars.\n");
    write("He used it when he created the world.\n");
    write("You probaly can't use it.\n");
}

init() {
    if (!new_object && call_other(this_player(), "query_level") > 19) {
	add_action("light"); add_verb("light");
	add_action("silence"); add_verb("silence");
	add_action("wave"); add_verb("wave");
	add_action("fetch"); add_verb("fetch");
	add_action("low_remove"); add_verb("low_remove");
	add_action("destr"); add_verb("destr");
	add_action("rem_room"); add_verb("rem_room");
	add_action("crash"); add_verb("crash");
	add_action("echo"); add_verb("$");
	add_action("trace"); add_verb("trace");
	add_action("remove"); add_verb("remove");
	add_action("find"); add_verb("find");
	add_action("patch"); add_verb("patch");
	add_action("lookplayer"); add_verb("lookplayer");
    }
}

id(str)
{
    if (new_object)
	return str == new_name;
    return str == "wand" || str == "wand of creation";
}

wave(str)
{
    if (str && !id(str))
	return 0;
    if (new_object)
	return 0;
    write("The wand gets warm, and activates.\n");
    write("You are now creating a new object.\n");
    if (call_other(this_player(), "query_level") < 20) {
	write("Something falters ...\n");
	return 1;
    }
    write("Give the name of the object: ");
    say(call_other(this_player(), "query_name") +
	" waves the wand of creation.\n");
    input_to("set_new_name");
    return 1;
}

set_new_name(str)
{
    if (str == "") {
	write("Aborted\n");
	return;
    }
    new_name = lower_case(str);
    write("Give the short description of the object: ");
    input_to("set_new_short");
}

set_new_short(str)
{
    if (str == "") {
	write("Aborted\n");
	return;
    }
    new_short = str;
    write("Give the long description of the object (terminate with '**'):\n");
    input_to("set_new_long");
    new_long = 0;
}

set_new_long(str)
{
    if (str == "") {
	write("Aborted.\n");
	return;
    }
    if (str == "**") {
	write("Give the value of the object: ");
	input_to("set_new_value");
	return;
    }
    if (new_long)
	new_long = new_long + str + "\n";
    else
	new_long = str + "\n";
    input_to("set_new_long");
}

set_new_value(str)
{
    if (str == "") {
	write("Aborted.\n");
	return;
    }
    if (sscanf(str, "%d", new_value) == 1) {
	new_object = 1;
	write("DONE.\n");
	say(call_other(this_player(), "query_name") +
	    " has created " + new_short + ".\n");
	move_object(clone_object("wand"), this_player());
	return;
    }
    write("Bad value. Aborted.\n");
}

get()
{
    return 1;
}

reset(arg) {
    if (!arg)
	set_light(1);
}

crash() {
    shout("You hear a distant rumble.\n");
    shout(call_other(this_player(), "query_name") +
	" has entered the game.\n");
    write("Ok.\n");
    return 1;
}

echo(str) {
    if (!str)
	return 0;
    say (str + "\n");
    return 1;
}

trace(str) {
    object ob;
    if (call_other(this_player(), "query_level") < 20) {
	write("Failure.\n");
	return 1;
    }
    if (!str) {
	write("Give monster name as argument.\n");
	return 1;
    }
    ob = present(str, environment(this_player()));
    if (!ob)
	ob = find_living(str);
    if (!ob) {
	write("No " + str + " found.\n");
	return 1;
    }
    write(ob); write("\n");
    write(environment(ob)); write("\n");
    return 1;
}

remove() {
    object ob;
    if (call_other(this_player(), "query_level") < 20) {
	write("Failure.\n");
	return 1;
    }
    ob = environment(this_player());
    if (!ob) {
	write("Not found. This should not happen !\n");
	return 1;
    }
    call_other(this_player(), "X#players/" + 
	call_other(this_player(), "query_name") + "/workroom");
    destruct(ob);
    return 1;
}

find(str) {
    object ob;

    if (!str)
	return 0;
    ob = find_object(str);
    write(ob);
    return 1;
}

patch(str) {
    string name, with, what;
    int iwhat;
    object ob;

    if (!str)
        return 0;
    if (sscanf(str, "%s %s %d", name, with, what) == 3)
        iwhat = 1;
    else if (sscanf(str, "%s %s %s", name, with, what) != 3) {
	if (sscanf(str, "%s %s", name, with) == 2)
	    iwhat = 0;
	else
	    return 0;
    }
    if (name == "here")
	ob = environment(this_player());
    else
	ob = present(name, environment(this_player()));
    if (what == "me")
	what = this_player();
    if (!ob)
	ob = find_living(name);
    if (!ob) {
        write("No such object here.\n");
	return 1;
    }
    write("Got: "); write(call_other(ob, with, what)); write("\n");
    say(call_other(this_player(), "query_name") +
	" patched the internals of " + call_other(ob, "short") + ".\n");
    return 1;
}

rem_room(str) {
    object ob;

    ob = find_object(str);
    if (!ob) {
	write("No shuch object.\n");
	return 1;
    }
    destruct(ob);
    write("Ok.\n");
    return 1;
}

destr(obj) {
    object ob;
    ob = present(obj, this_player());
    if (!ob) {
	write("No such object.\n");
	return 1;
    }
    write("Ok.\n");
    say(call_other(this_player(), "query_name") + " got rid of " +
	call_other(ob, "short") + ".\n");
    destruct(ob);
    return 1;
}

low_remove(num)
{
    int n;
    object ob;

    if (sscanf(num, "%d", n) != 1)
	return 0;
    ob = first_inventory(environment(this_player()));
    while(n>0 && ob) {
	n -= 1;
	ob = next_inventory(ob);
    }
    if (ob == this_player()) {
	write("That is your self !\n");
	return 1;
    }
    write("Destroying: " + call_other(ob, "short") + ".\n");
    destruct(ob);
    return 1;
}

fetch(str) {
    move_object(str, this_player());
    return 1;
}

silence(str) {
    object ob;

    ob = find_living(str);
    if (!ob) {
	write("No such player.\n");
	return 0;
    }
    call_other(clone_object("obj/shout_curse"), "start", ob);
    write("Ok.\n");
    return 1;
}

lookplayer(str) {
    object ob;
    int i;
    if (!str)
	return 0;
    ob = find_living(str);
    if (!ob)
	return 0;
    write("Inventory of " + call_other(ob, "short") + ":\n");
    i = 0;
    ob = first_inventory(ob);
    while(ob) {
	string short_str;
	write(i + "\t");
	short_str = call_other(ob, "short");
	if (short_str)
	    write(short_str + ",\t");
	write(ob); write("\n");
	ob = next_inventory(ob);
	i += 1;
    }
}

light() {
    write("Total light: " + set_light(0) + "\n");
    return 1;
}
