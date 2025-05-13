inherit "obj/armour";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

    set_name("wolfen apron");
    set_alias("apron");
    set_type("armour");
    set_short("a wolfen cook's apron");
    set_long("A dirty apron.  You see smears of grease all over it.\n");
    set_value(200);
    set_ac(1);
    set_weight(1);
}
