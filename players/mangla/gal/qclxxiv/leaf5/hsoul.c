id(str) { return str == "herbalsoul174"; }
get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

reset(arg) {
	if (arg) return;
	call_out("selfdest", 30);
}

selfdest() { destruct(this_object()); }
