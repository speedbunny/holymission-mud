/*coded by tatsuo for the npc's in the samurai guild*/

inherit "/obj/weapon";

  reset(arg)
{
	::reset(arg);
	if (arg) return;
	set_name("sabre");
	set_short("a sabre");
	set_long("A simple sabre.  ...It emits a faint humming sound.\n");
	set_class(random(20)+1);
	set_value(1000);
	set_weight(random(4)+1);

return 1;
}
