/*coded by tatsuo for the npc's in the samurai guild*/

inherit "/obj/weapon";

  reset(arg)
{
	::reset(arg);
	if (arg) return;
        set_name("abacus");
       set_short("An Abacus");
      set_long("This is an abacus. It is used to calculate numbers rapidly.\n");
      set_class(0);
      set_value(500);
      set_weight(2);
return 1;
}
