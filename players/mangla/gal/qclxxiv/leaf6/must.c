inherit "obj/food";

reset(arg) {
	if(arg) return;
	set_name("must");
	set_short("Must");
	set_long("Some piece of dirt covered with must.\n");
	set_value(6);
	set_weight(1);
	set_eater_mess( "Bwah! Only animals eat such disgusting things.\n");
	set_strength(5);
}
