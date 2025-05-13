inherit "/obj/treasure";
void reset ( int tick ) {
    ::reset ( tick);
    if ( tick ) return;
   set_name("talisman");
	set_alias("paper");
    set_short("yellow paper talisman");
    set_long("A rectangular piece of yellow paper with many red runes painted on it. This is a talisman from the taoist temple for good luck and removing curse.\n");
    set_weight(1);
    set_value(10);
}

int query_object_type(){
    return 2;
}

int query_three_quest(){
    return 1;
}
