/* antigrav.c */

int weight;

short() {
    return "A small magic stone with a strange weight";
}

long() {
    write("This is a small stone, and you understand that it must be magic.\n" +
	  "Somehow its weight doesn't feel right...\n");
    if (weight < 0)
	write("If you didn't know better, you would guess\n" +
	      "that it weighs less than nothing!\n");
        write("The weight of this stone is currently " +
	      weight + ".\n");
	write("        You can set the weight ('set weight') to whatever you like!\n");
} /* long */

reset(arg) {
    if (!arg)
	weight = -1;
}

init() {
    add_action("set"); add_verb("set");
}

set(str) {
    string what; int how;

    if (!this_player()->query_wizard()) return;
    if (!str)
	return 0;
    if (sscanf(str, "%s %d", what, how) != 2)
	return 0;
    if (what != "stone" && what != "weight")
	return 0;

    weight = how;
    return 1;
} /* set */

id(str) {
    return    str == "stone" || str == "magic stone"
	   || str == "stone of gravity";
}

get() {
    return 1;
}
drop() {
  return;
 } 

query_name() { return "stone"; }
query_weight() { return weight; }
set_weight(w) { weight = w; }

query_value() {
    if (weight < 0)
	return -100 * weight;
    else
	return 5;
}
