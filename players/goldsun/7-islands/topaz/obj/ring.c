inherit "obj/armour";

void reset(int i)
{
 ::reset(i);
 if (i) return;
 set_name("topaz ring");
 set_short("Topaz ring");
 set_type("ring");
 set_ac(1);
 set_long("A golden ring with topaz eye.\n");
 set_value(400);
 set_weight(1);
}



