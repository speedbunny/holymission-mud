inherit "obj/monster";
reset(arg){
    ::reset(arg);
    if(! arg) {
	set_name("juicer");
	set_short("Juicer");
	set_long("This is a JUICER! A juicer is a person who wasn't born with\n"+
	  "super powers like a giants strength or a dragons speed. Who\n"+
	  "wants to spend years learning magic in some school? So they\n"+
	  "have turned to high-teck drugs. Now they can move like a bird\n"+
	  "and hit like a boulder! The only problem is that so many drugs\n"+
	  "take there tole on the body, but who cares! Live fast, Fight hard\n"+
	  "and die in combat!\n");
	set_level(15);
	set_number_of_arms(4);
	set_al(-1000);
	set_ac(50);
	set_wc(20);
	set_aggressive(1);
    }
}
