/* Axlrose - Human Army */
/* Soldier's Chain Mail Armor */ 
inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("fine interlocked steel pieces");
    set_alias("chains");
    set_type("armour");
    set_ac(3);
    set_short("Chained metal and leather armor");
    set_long
    ("A soft, quilted leather and padded body suit with an overlapping layer \n"
      +"of fine interlocked steel pieces.  The fine mesh appears crafted in \n"
      +"such a way that each link locks into another link while still having \n"
      +"flexibility overall.\n");
    set_size(3);
    set_value(750);
    set_weight(3);
}
