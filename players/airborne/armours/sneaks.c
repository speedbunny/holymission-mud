inherit "/obj/armour";

reset(arg){
    ::reset(arg);
    if(arg) return 1;
	set_name("reeboks");
	set_type("boots");
	set_alias("sneaks");
	set_ac(1);
	set_weight(1);
	set_short("Reeboks");
	set_long("These are a really kool pair of Reeboks.  All black.\n");
   return 1;
}
