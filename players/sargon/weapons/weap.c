inherit "obj/weapon";

reset(arg) 
{
  ::reset(arg);
    if(!arg) {
    set_name("White Bishops Longsword");
    set_alt_name("sword");
    set_alias("Sword");
    set_short("White Bishops Longsword\n");
    set_long("This is the weapon of choice of the White Bishop\n");
    set_class(20);
    set_type(1);
    set_weight(8);
    set_value(2000);
    }
}





