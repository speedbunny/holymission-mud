/*coded by tatsuo for the npc's in the samurai guild*/

inherit "/obj/weapon";

  reset(arg)
{
	::reset(arg);
	if (arg) return;
        set_name("wakizashi");
	set_short("A Wakizashi");
        set_long("It is a wakizashi, a small wickedly sharp curved blade carried by samurai");
	set_class(16);
	set_value(8000);
	set_weight(2);

return 1;
}
