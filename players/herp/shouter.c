id(str) { return str="shouter"; }

short() { return "A shouter"; }

init() { add_action("do_shout","schaut"); }

do_shout(str) { shout(str); }

get() { return 1; }
