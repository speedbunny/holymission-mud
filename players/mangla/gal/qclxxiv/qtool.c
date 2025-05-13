int hidden;
string name;
string alias;
string shortdesc;
string longdesc;

set_name(s) {name=s;}
set_alias(s) {alias=s;}
set_short(s) { shortdesc=s; }
set_long(s) { longdesc=s; }

reset(arg) {
	if (arg) return;
}

short() { 
	if (hidden) return 0;
	return shortdesc; 
}

long() { 
	write( longdesc); 
}

id(arg) { return arg==name || (alias && arg==alias); }

init()  { 
	add_action("hide", "hide" );
}

hide(arg) {
	if (id(arg)) {
		if (hidden) hidden=0; else hidden=1;
		return 1;
	}
	return 0;
}

