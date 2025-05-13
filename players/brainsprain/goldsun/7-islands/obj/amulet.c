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
 set_long(
"An amulet of the silver fox. Sighart's sign is engraved on it.  It feels "+
"as if the wizard Sighart has imbued this amulet with protective powers.  "+
"Attached to the top of the amulet is a heavy silver chain.\n");
 set_size(0);
 set_ac(1);
}

