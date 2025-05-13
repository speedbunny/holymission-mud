inherit "obj/armour";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("leather jacket");
    set_short("A leather jacket");
    set_alias("jacket");
    set_long("A worn but sturdy leather jacket.\n" +
      "On the back is a lot of rivets making the pattern of a star.\n");
    set_value(50);
    set_weight(2);
    set_ac(2);
    set_type("armour");
}
