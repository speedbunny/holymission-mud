inherit "obj/treasure";
string scent,note;

void long() {
    write(long_desc);
}

void reset(int arg) {
    if(arg) return;
    set_id("fixer");
    set_name("ringfixer");
    set_alias("fixer");
    set_short("Wedding Ring Fixer");
    set_long("\
To fix rings type: restore <target> <spouse>.\n");
    set_weight(0);
    set_value(10);
}

void init() {
    add_action("fix","restore");
}

status fix(string str) {
    string them, spouse;
    object target, ring;

    if(!str) {
	write("Usage is: restore <target> <spouse>\n");
	return (1);
    }
    if (sscanf(str, "%s %s", them, spouse) != 2) {
	write("Usage is: restore <target> <spouse>\n");
	return (1);
    }
    target = find_player(them);
    if (!target) {
	printf("But, %s isn't on!\n", them);
	return (1);
    }
    ring = clone_object("/players/moonchild/wedding/ring");
    ring -> name1(capitalize(spouse));
    ring -> name2(capitalize(them));
    move_object(ring, target);
    write("Ok.\n");
    return (1);
}
