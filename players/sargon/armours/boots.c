inherit "obj/armour";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

    set_name("White boots with leggings");
    set_alias("boots");
    set_type("boots");
    set_short("boots");
    set_long("White boots with attached leggings made for an Imperial guard\n");
    set_value(300);
    set_ac(2);
    set_weight(2);
    set_size(3);

}



