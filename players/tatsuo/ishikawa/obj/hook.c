/*coded by tatsuo for the npc's in the samurai guild*/

inherit "/obj/weapon";

  reset(arg)
{
	::reset(arg);
	if (arg) return;
	set_name("grappling hook");
	set_short("grappling hook");
	set_alias("hook");
	set_long("An iron grappling hook tied to a rope.\n");
	set_class(10);
	set_value(1000);
	set_weight(2);

return 1;
}
