inherit "/obj/weapon";

#define STR 0x01
#define DEX 0x02

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("longsword");
    set_alt_name("sword");
    set_alias("guard_sword");
    set_class(14);
    set_weight(4);
    set_type(STR & DEX);
    set_value(800);
    set_short("A fine longsword");
    set_long("This is a very big longsword which looks like it has\n"
    + "slayed many an enemy. There is something carved on it.\n");
    set_read("This sword is personel property of the bodyguard.\n"
            +"Nobody can use it like him.\n");
    set_hit_func(this_object());
  }
}

weapon_hit(ob) {
  return (wielded_by->id("bodyguard")) ? 16:0;
}
