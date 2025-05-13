inherit"obj/weapon";

reset(arg){
    ::reset(arg);
    if (arg) return;
    set_name("broadsword");
    set_alias("sword");
    set_class(16);
    set_short("A heavy broadsword");
    set_long("A heavy looking broadsword used by gladiators");
    set_weight(4);
    set_value(1500);
}
