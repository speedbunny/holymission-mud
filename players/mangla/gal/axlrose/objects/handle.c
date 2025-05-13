/* Axlrose - Barbarian Guild */
inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("leather bound metal handle");
    set_alias("handle");
    set_short("Shattered remains of a bastard sword");
    set_long
    ("A dry rotted leather wrapped handle of an once dwarven rune inscribed \n"
      +"bastard sword.  Acid burns are prominant over the remaining shattered \n"
      +"blade, dented guard, and broken pommel - leaving a corpse of the sword.\n");
    set_class(3);
    set_value(5);
    set_weight(1);
}
