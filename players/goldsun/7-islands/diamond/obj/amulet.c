inherit "obj/armour";

void reset(int i)
{
 ::reset(i);
 if (i) return;
 set_name("silver amulet");
 set_type("amulet");
 set_value(2000);
 set_weight(1);
 set_short("A silver amulet");
 set_long("An amulet of silver fox. Sighart's sign is engraved on it.\n"+
	  "Wizard Sighart has safety feeling with this amulet.\n");
 set_size(0);
 set_ac(1);
}

