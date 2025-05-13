/* Axlrose - Human Army */
/* Soldier's Reduced Footman's Mace */
inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("splintered ferrous studded club");
    set_alt_name("mace");
    set_alias("club");
    set_short("A splintered footman's mace");
    set_long
    ("A cracked and splintered wooden club approximately two feet long. \n"
      +"Stress seams circle around the few remaining blunt iron studs on the \n"
      +"wide end while the thin end wears the leather wrap down.\n");
    set_class(6);
    set_value(40);
    set_weight(2);
}
