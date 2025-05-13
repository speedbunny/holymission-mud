inherit "obj/thing";

reset(arg) {
    ::reset(arg);
    if(!arg){
	set_name("rock");
	set_weight(2);
	set_value(5);
	set_alt_name("lava rock");
	set_alias("stones");
	set_short("Rock");
       set_long("A piece of rock.\n"+
                "It looks like once melted lava.\n"+
                "It has a black shimmering look.\n"+
                "It feels cold now.\n");
         set_can_get(1);
    }
}
