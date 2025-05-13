#pragma strict_types

inherit "obj/thing";

void reset(int arg){
    ::reset(arg);
    if (arg) return;
    set_name("crystal");
    set_weight(0);
    set_light(50);
    set_value(3000);
    set_short("A shining crystal");
    set_long("The amazing sun crystal.\n");
}
