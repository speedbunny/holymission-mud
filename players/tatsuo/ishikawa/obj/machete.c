/*coded by tatsuo for the npc's in the samurai guild*/

inherit "/obj/weapon";

  reset(arg)
{
	::reset(arg);
	if (arg) return;
	set_name("machete");
	set_short("machete");
	set_long("A short sharp blade used for hacking through jungles.\n");
	set_class(10);
	set_value(1000);
	set_weight(2);

return 1;
}
