/*coded by tatsuo for the npc's in the samurai guild*/

inherit "/obj/weapon";

  reset(arg)
{
	::reset(arg);
	if (arg) return;
	set_name("katana");
	set_short("A Katana");
	set_long("It is a katana, a long curved sword carried by mighty samurai.\n");
	set_class(20);
	set_value(12000);
	set_weight(3);

return 1;
}
