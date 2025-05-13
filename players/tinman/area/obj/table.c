inherit "/obj/treasure";
void reset ( int tick ) {
    ::reset ( tick);
    if ( tick ) return;
    set_name("table");
    set_short("A sturdy bamboo table");
    set_long("A rectangular smooth top bamboo table for everyday use.\n");
    set_weight(12);
    set_value(200);
}

int query_object_type(){
    return 3;
}

int query_three_quest(){
    return 1;
}
