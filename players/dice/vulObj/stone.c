inherit "obj/thing";

reset(arg) {
    ::reset(arg);
    if(!arg){
	set_name("stone");
	set_weight(2);
	set_value(5);
	set_alt_name("lava stone");
	set_alias("stones");
	set_short("Stone");
       set_long("A piece of stone.\n"+
                "It looks like once melted lava.\n"+
                "It has a black shimmering look.\n"+
                "It feels cold now.\n");
         set_can_get(1);
    }
}
