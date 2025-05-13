int state;
id(str) { return str == "cloud" || str == "cigar smoke"; }
short() { return "A cloud of cigar smoke"; }
get()	{ return 0; }
query_weight() { return 0; }

reset(arg) {
	if (arg) return;
	state = 0;
	call_out("smokestate",4+random(3));
	return 1;
}

bsay(str) {
	if (str && environment(this_object()))
		tell_room(environment(this_object()), str);
}

smokestate() {
	state++;
	if (state==1) bsay("A cloud of cigar smoke coils in the air.\n");
	else if (state==2) bsay("A cloud of cigar smoke curls in the air.\n");
	else if (state==3) bsay("A cloud of cigar smoke starts fading away.\n");
	else bsay("A cloud of cigar smoke has nearly faded away.\n");
	if (state==5) destruct(this_object());
	call_out("smokestate",4+random(3));
}
