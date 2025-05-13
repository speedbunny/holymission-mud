inherit "obj/monster";
reset(arg) {
    ::reset (arg);
    if(arg) return;
    set_name("halfling guard");
    set_alias("guard");
    set_level(12);
    set_wc(14);
    set_ac(4);
    set_al(0);
    set_gender(1);
    set_race("halfling");
    set_short("Guard");
    set_long("The halfling guard is standing as tall as he possibly can\n"+
      "while on duty.  His clothes are clean as is his skin.\n");
    add_money(125);
}

void init() {
    ::init();
    add_action("_west","west");
}

_west() {

    if( this_player()->query_immortal() )
	return( 0 );
    write("The halfling says:  You are not allowed to go in.\n");
    return 1;
}
