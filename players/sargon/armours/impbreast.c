inherit "obj/armour";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

    set_name("Stormtrooper breastplate");
    set_alias("breastplate");
    set_type("armour");
    set_short("breastplate");
    set_long("A clean white and polished breastplate of the Imperial guard.\n");
    set_value(3000);
    set_ac(3);
    set_weight(3);
    set_size(3);


}



