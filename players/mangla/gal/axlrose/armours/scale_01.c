/* Axlrose - Human Army */
/* Soldier's Scale Armor */
inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("oval-shaped ferrous pieces");
    set_alias("scales");
    set_type("armour");
    set_ac(2);
    set_short("Scaled metal and leather armor");
    set_long
    ("A soft leather coat covered with numerous overlapping oval ferrous \n"
      +"metal pieces.  The course mesh appears scaled in design, though some \n"
      +"pieces are occasionally missing.\n");
    set_size(3);
    set_value(450);
    set_weight(3);
}
