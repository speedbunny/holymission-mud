/* Axlrose - Human Army */
/* Soldier's Chain Mail Coif */
inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("chain linked helm");
    set_alt_name("helm");
    set_alias("coif");
    set_type("helmet");
    set_ac(2);
    set_short("Steel soldier's coif");
    set_long
    ("A padded hood of leather covered with a fine mesh of chain mail.  The \n"
      +"helmet protects the head and upper shoulders, through leaving the face \n"
      +"exposed.\n");
    set_size(3);
    set_value(75);
    set_weight(2);
}
