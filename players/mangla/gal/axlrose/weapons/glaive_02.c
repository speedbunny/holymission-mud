/* Axlrose - Human Army */
/* Soldier's Shortened Glaive Polearm */
inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("bladed pine staff");
    set_alt_name("polearm");
    set_alias("glaive");
    set_short("A shortened glaive polearm");
    set_long
      ("A slender single-edged iron blade mounted to an approximately six foot \n"
      +"rough pine staff by a dark leather cord.\n");
    set_class(8);
    set_value(30);
    set_weight(2);
}

