inherit"obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_alias("cap");
    set_name("Ranma's Army Cap");
    set_type("helmet");
        set_short("Ranma's Army Cap");
	set_long(
 	"An enchanted Nihonese army cap, Ranma wears it all the time.\n");
    set_weight(1);
    set_ac(1);
    set_size("any");
    set_value(2000);
}
