inherit "obj/armour"; 

void reset(int arg) 
{
    ::reset(arg);
    if(arg) return;

    set_name("Leather Gloves");
    set_alias("gloves");
    set_short("Soft Leather Gloves");
    set_long("These are fine leather gloves, well tanned and comfortable.\n");
    set_type("glove");
    set_size(2);
    set_weight(1);
    set_value(200);
    set_ac(1);
}
