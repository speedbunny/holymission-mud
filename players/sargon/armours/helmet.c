inherit "obj/armour";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

    set_name("White helmet and face shield");
    set_alias("helmet");
    set_type("helmet");
    set_short("helmet");
    set_long("A white helmet with a face shield worn by the Imperial guard.\n");
    set_value(300);
    set_ac(1);
    set_weight(2);
    set_size(3);

}



