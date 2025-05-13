inherit "obj/armour";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("Shield of Light");
  set_type("shield");
  set_alias("shield of light");
  set_short("A Shield of Light");
  set_long("This shield shines brightly with it's own inner radiance.\n");
  set_ac(1);
  set_weight(2);
  set_value(750);
  set_arm_light(1);
}
