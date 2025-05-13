inherit "/obj/treasure";
string es;
set_extra_long(s) { es = s; }

reset(arg) {
	set_value(0);
	set_weight(5);
}

set_name(s) {
	name = s;
	::set_short(s);
	::set_alias(s+"174");
	set_long(s+", worthless to anyone but dwarfs.\n" );
}

long() {
	::long();
	if (es) write(es);
}
