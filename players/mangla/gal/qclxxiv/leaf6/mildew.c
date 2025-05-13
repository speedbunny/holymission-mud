inherit "obj/food";

reset(arg) {
	if(arg) return;
	set_name("mildew");
	set_short("Mildew");
	set_long("Some piece of dirt covered with mildew.\n");
	set_value(5);
	set_weight(1);
	set_eater_mess( "Faugh! That tasted disgusting. Are you that hungry?\n");
	set_strength(3);
}
