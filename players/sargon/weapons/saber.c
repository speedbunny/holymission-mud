inherit "obj/weapon";

reset(arg) 
{
  ::reset(arg);
    if(!arg) {
    set_name("White Knight's Saber");
    set_alt_name("saber");
    set_alias("saber");
    set_short("White Knight's Saber\n");
    set_long("This is the weapon of choice of the White Knight\n");
    set_type(1);
    set_weight(4);
    set_class(25);
    set_value(2000);
    }
}





