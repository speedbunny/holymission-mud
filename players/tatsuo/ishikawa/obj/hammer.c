/*coded by tatsuo for the npc's in the samurai guild*/

inherit "/obj/weapon";

  reset(arg)
{
	::reset(arg);
	if (arg) return;
        set_name("hammer");
        set_short("A Blacksmith Hammer");
        set_long("This is a hammer used by blacksmiths to forge weapons. The steel head is\n"+
                 "attached to a thick wooden handle. There is soot covering the entire hammer.\n");
       set_class(6);
       set_value(1000);
       set_weight(4);
return 1;
}
