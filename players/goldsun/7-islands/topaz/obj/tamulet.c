inherit "obj/armour";

void reset(int i)
{
 ::reset(i);
 if (i) return;
 set_name("amulet");
 set_short("Topaz amulet");
 set_type("amulet");
 set_ac(1);
 set_long("Lether amulet with topaz eye.\n");
 set_value(100);
 set_weight(1);
}


