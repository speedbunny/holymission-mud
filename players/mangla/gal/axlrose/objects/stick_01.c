/* Axlrose - Weapon Remains */ 
inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("splintered pine staff");
    set_alt_name("pole");
    set_alias("stick");
    set_short("splintered pine pole");
    set_long
      ("The remaining cracked and splintered end of a glaive polearm.  This \n"
      +"rough pine staff is approximately four feet long.\n");
    set_class(2);
    set_value(5);
    set_weight(1);
}

