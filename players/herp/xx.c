string name;

query_real_name() { return name; }

init() {
    add_action("dos","dos");
    add_action("don","don");
}

don(str) { name=str; }

dos() { shadow(this_player(),1); }
