inherit "/obj/weapon";

reset(arg)
{
  if (arg) return;
  set_value(100000);
  set_short("scroll");
  set_long("A bright scroll.");
  set_id("scroll");
  set_weight(1);
  set_type(2);
  }
