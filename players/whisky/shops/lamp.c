string amount_of_fuel;
string name;
status is_lighted;
int weight;

long() {
    write(short() + "\n");
}

reset(arg) {
    if (arg)
	return;
amount_of_fuel = 3000; name = "lamp"; is_lighted = 0; weight = 1;
}

set_weight(w) { weight = w; }

query_weight() { return weight; }

query_is_lit() { return is_lighted; }

short() {
    if (is_lighted)
return "An Oil Lamp(lighted)";
return "An Oil Lamp";
}

set_name(n) { name = n; }
set_fuel(f) { amount_of_fuel = f; }

init() {
    add_action("light", "light");
    add_action("extinguish", "extinguish");
}

light(str) {
    if (!str || str != name)
	return 0;
    if (is_lighted) {
write("You have your Oil Lamp already lighted.\n");
	return 1;
    }
    is_lighted = 1;
    call_out("out_of_fuel", amount_of_fuel * 2);
    if (set_light(1) == 1) {
	write("You can see again.\n");
	say(call_other(this_player(), "query_name") +
	    " lights a " + name + "\n");
    } else
	write("Ok.\n");
    amount_of_fuel = 0;
    return 1;
}

out_of_fuel() {
    object ob;
    if (set_light(-1) == 0)
say("It turns dark as "+this_player()->query_name()+"'s "+name+" goes dark.\n");
    else
say (this_player()->query_name()+"'s "+name+" goes dark.\n");

#if 0
/* Herp: destruct reduces the weight itself ... don't do add_weight !
#endif
    ob = environment(this_object());
    if (living(ob))
	call_other(ob, "add_weight", -weight);
#if 0 
*/
#endif
    destruct(this_object());
}

id(str) {
    return str == name;
}

query_value() {
  return 50;
}

get() { return 1; }

extinguish(str) {
    int i;

    if (str && !id(str))
	return 0;
    if (!is_lighted)
	return 0;
    i = remove_call_out("out_of_fuel");
    if (i == -1) {
	write("Error.\n");
	return 1;
    }
    amount_of_fuel = i/2;
    is_lighted = 0;
    if (set_light(-1) == 0) {
write("Your Oil Lamp suddenly turns dark.\n");
	say(call_other(this_player(), "query_name") +
	    " extinguishes the only light source.\n");
    } else {
	write("Ok.\n");
    }
    return 1;
}
