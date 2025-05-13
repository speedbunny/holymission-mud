/* Axlrose - Human Army */
/* Soldier's Iron Helm */
inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("circular iron helm");
    set_alias("helm");
    set_type("helmet");
    set_ac(1);
    set_short("Iron footman's helm");
    set_long
    ("A medium sized circular iron helmet with a flared brim and occasional \n"
      +"dent.  Soft padding lines the inside while laced with leather chin \n"
      +"straps.\n");
    set_size(3);
    set_value(50);
    set_weight(1);
}
