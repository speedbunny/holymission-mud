id(str) { return str=="ball"; }
short() { return "ball"; }
long() { write(short()+".\n"); }
reset(arg) {
    if (arg) return;
    enable_commands();
}

set_command_modifier() { set_modify_command(this_object()); }

modify_command(str) { write(str+"\n"); return str; }
