/* Axlrose - Human Army */
/* Soldier's Shattered Broad Sword */
inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("shattered steel sword");
    set_alias("sword");
    set_short("A shattered steel military sword");
    set_long
    ("The remains of a double-edged, heavy military sword.  The dull corpse \n"
      +"of a steel blade measures approximately a foot in length.  The hilt has \n"
      +"the leather wrap worn down while the shell guard is smashed inward.\n");
    set_class(5);
    set_value(50);
    set_weight(1);
}
