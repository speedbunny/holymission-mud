inherit "/obj/weapon";

void reset(int i)
{
 ::reset(i);
 if (i) return;
 set_name("bear claw");
 set_alias("claw");
 set_class(18);
 set_short("A claw");
 set_long("A very sharp claw of Ice bear. It is 4 feet long.\n");
 set_weight(4);
 set_value(3500);
}

