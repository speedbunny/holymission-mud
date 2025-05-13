
inherit "/obj/weapon";

  reset(arg)
{
	::reset(arg);
	if (arg) return;
        set_name("orcrist");
        set_short("orcrist");
        set_alias("sword");
        set_alt_name("orc slayer");
        set_long("This is the mighty orc slayer Orcrist. The blade gleams \n"+
        "with a dull blue light and has numerous swirled runes etched into \n"+
        "it's polished blade. You can sense an overwhelming hatred of orcs as \n"+
        "you grab the hilt.\n");
        set_class(3);
        set_value(1000);
	set_weight(2);
        set_hit_func(this_object());

   }
weapon_hit(attacker) {

    if (attacker->query_race()=="orc") {
write("Orcrist emited a brilliant blue flame as it attacks it's most hated enemy! \n");
      return (attacker->query_max_hp()-1);
    }
     else
      return 0;
  }
