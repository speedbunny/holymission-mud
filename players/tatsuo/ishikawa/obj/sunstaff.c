/*coded by tatsuo for the npc's in the samurai guild*/

inherit "/obj/weapon";

  reset(arg)
{
	::reset(arg);
	if (arg) return;
      set_name("sunstaff");
	set_short("The sunstaff of Amaterasu");
	set_long("A six foot staff, two inches in diameter.  Atop the staff\n"+
	         "is fixed an orniment in the shape of the setting sun.\n"+
	         "Set inside the orniment is a crystal.\n");
	set_class(10);
	set_value(1000);
	set_weight(2);

return 1;
}
