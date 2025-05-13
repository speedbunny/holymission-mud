inherit "obj/armour";

void reset(int arg) 
{
    ::reset(arg);
    if(arg) return;

    set_name("Ring of Protection");
    set_alias("platinum ring");
    set_type("ring");
    set_size(0);
    set_short("A Shiny Platinum Ring");
    set_long(
      "This is a small platinum ring, yet when you put it on, it\n"+
      "expands to fit your finger!\n");
    set_ac(1);
    set_weight(2);
    set_value(475);
}
