inherit "obj/food";

reset(arg) {
	if(arg) return;
	set_name("curry goat");
	set_alias("goat");
	set_short("Curry goat");
	set_long("Ital curry goat, smelling deliciously.\n");
	set_value(500);
	set_weight(2);
	set_eater_mess(
     "Wow, this massala curried goat really tastes ENORMOUSLY good. Irie!\n");
	set_strength(70);
}
