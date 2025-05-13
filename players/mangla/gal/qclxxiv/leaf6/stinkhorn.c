inherit "obj/food";

reset(arg) {
	if(arg) return;
	set_name("stinkhorn");
	set_short("A stinkhorn");
	set_long("A stinkhorn, spreading it's ugly smell.\n");
	set_value(15);
	set_weight(2);
	set_eater_mess( 
	"Man!!!! This is sickening. You start to vomit. You must be desparate!.\n");
	set_strength(12);
}

eat(arg)
{
	if (arg=="stinkhorn") {
		this_player()->set_alignment("stinking");
		::eat(arg);
		return 1;
	}
	return 0;
}
