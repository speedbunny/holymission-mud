inherit "obj/food";

reset(arg) {
	if(arg) return;
	set_name("massala chicken");
	set_alias("chicken");
	set_short("Massala chicken");
	set_long("Ital and more than delicious massala chicken.\n");
	set_value(400);
	set_weight(2);
	set_eater_mess(
    	"As you eat up the ital massala chicken, a smile covers your face.\n");
	set_strength(50);
}
