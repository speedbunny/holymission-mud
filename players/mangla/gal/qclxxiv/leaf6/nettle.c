inherit "obj/food";

reset(arg) {
	if(arg) return;
	set_name("nettle");
	set_short("A stinging nettle");
	set_value(25);
	set_weight(2);
	set_eater_mess( 
	"You had better cooked them before eating them. Your mouth is on fire.\n");
	set_strength(15);
}

