inherit "obj/armour";

reset(arg) 
{
  ::reset(arg);
    if(!arg) {
    set_name("dragonmail");
    set_alias("mail");
    set_type("armour");
    set_ac(4);
    set_size(4);
    set_short("Dark Dragonmail");
    set_long("A deep brown scalemail of a dracolisk, it seems tougher yet"+
    " lighter than steel.\n");
    set_weight(3);
    set_value(3500);
    }
}





