inherit "obj/armour";

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return;

  set_name("Steel Boots");
  set_alias("steel boots");
  set_type("boots");
  set_size(0);
  set_short("A Pair of Engraved Steel Boots");
  set_long("This fur lined pair of metal boots is covered with strange engravings.\n");
  set_ac(1);
  set_weight(3);
  set_value(575);
}
