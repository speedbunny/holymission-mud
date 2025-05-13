inherit "/obj/treasure";
void reset ( int tick ) {
    ::reset ( tick);
    if ( tick ) return;
    set_name("cloth");
    set_short("A silk ceremonial table cloth");
    set_long("A yellow silk ceremonial table cloth about 5 to 6 feet in length. Runes are written all over the helm and a yin/yang symbol in the middle\n");
    set_weight(2);
    set_value(200);
}

int query_object_type(){
    return 5;
}

int query_three_quest(){
    return 1;
}
