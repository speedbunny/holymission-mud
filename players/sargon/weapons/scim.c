inherit "obj/weapon";

reset(arg) 
{
  ::reset(arg);
    if(!arg) {
    set_name("scimitar");
    set_alias("scimitar");
    set_alt_name("sword");
    set_short("A gleaming scimitar");
    set_long("This curved blade is sharp unlike anyother, it's glow radiates not"+
    " from magic, but from the metal itself, Adamanitine. If used properly "+
    "it can vanquish any foe.\n");
    set_class(20);
    set_type(1);
    set_weight(4);
    set_value(2000);
    }
}





