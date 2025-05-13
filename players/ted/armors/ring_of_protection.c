inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Ring of Protection");
    set_alias("platinum ring");
    set_type("ring");
    set_size("any");
    set_short("A Shiny Platinum Ring");
    set_long(
      "This is a small platinum ring, yet when you put it on, it\n"+
      "expands to fit your finger!\n");
    set_ac(1); // Colossus 070394: Changed from 2 to 1
    set_weight(2);
    set_value(475);
}
