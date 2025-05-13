inherit "obj/armour";

void reset(int i)
{
 ::reset(i);
 if (i) return;
 set_name("bear fur");
 set_alias("fur");
 set_short("A white fur");
 set_long("A white bear fur. It is pleasant warm.\n");
 set_size(4);
 set_value(2300);
 set_weight(2);
 set_ac(4);
 set_type("armour");
}

