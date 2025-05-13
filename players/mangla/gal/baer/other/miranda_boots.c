inherit "obj/armour";

reset(arg)
{
  ::reset(arg);
  set_name("long black boots");
  set_alias("boots");
  set_short("Long black boots");
  set_long("These knee high boots, are those worn by the Emperor's " +
           "personal guards. They are made of fine black leather " +
           "and are very durable.\n");
  set_ac(1);
  set_weight(2);
  set_value(500);
  set_type("boot");
}

