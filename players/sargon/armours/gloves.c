inherit "obj/armour";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

    set_name("White gloves");
    set_alias("gloves");
    set_type("glove");
    set_short("gloves");
    set_long("These a gloves worn by the Imperial guard.\n");
    set_value(200);
    set_ac(1);
    set_weight(2);
    set_size(3);


}



