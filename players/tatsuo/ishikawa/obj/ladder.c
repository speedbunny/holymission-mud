/*coded by tatsuo for the npc's in the samurai guild*/

inherit "/obj/treasure";

  reset(arg)
{
	::reset(arg);
	if (arg) return;
	set_name("ladder");
	set_short("A ladder");
	set_long("A tall ladder.  It looks rather heavy.  If you\n"+
	         "prop it against the wall, it might reach the 'ceiling'.\n");
	set_value(1000);
	set_weight(100);

return 1;
}
