inherit "obj/armour";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("elven cloak");
    set_alias("cloak");
    set_type("cloak");
    set_ac(1);
    set_weight(0);
    set_value(1000);
    set_short("elven cloak");
    set_long("\
This is a dull grey cloak worn by the Elven warriors of Regulost.\n\
Elven magic makes the fabric blend into surroundings making\n\
it hard for the wearer's foes to hit them.  The Elven fabric\n\
is nearly weightless!\n");
}
