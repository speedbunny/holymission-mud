inherit "obj/treasure";

reset(arg)
{
	if(arg) return;
	::reset(arg);
	set_short("A magical stone");
	set_long("This is a magical stone. You might be able to rub it.\n");
	set_id("magical stone");
	set_alias("stone");
	set_value(2500);
	set_weight(1);
}

init()
{
	::init();
	add_action("rub_stone", "rub");
}

rub_stone(arg)
{
	if(!id(arg)) return;
	write("You are totally healed. The stone crumbles to dust.\n");
	destruct(this_object());
	return 1;
}
