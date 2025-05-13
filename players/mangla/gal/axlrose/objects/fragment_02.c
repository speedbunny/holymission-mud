/* Axlrose - Human Army */
/* Footman's Mace Fragments */
inherit "obj/treasure";

reset(arg) {
    if (arg) return;
    set_name("ferrous studded wooden fragments");
    set_alt_name("fragments");
    set_alias("pieces");
    set_short("splintered ferrous and wood pieces");
    set_long
    ("Various shaped and sized pieces of blunted iron studs embedded in \n"
      +"splintering weakened wood fragments.\n");
    set_value(5);
    set_weight(1);
}
