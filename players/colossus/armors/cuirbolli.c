inherit"obj/armour";

reset(arg){
    ::reset(arg);
    if (arg) return;
    set_name("cuirbolli");
set_alias("leather");
    set_short("A cuirbolli");
    set_long("This is the suit of leather armor commonly worn by the Roman Legion.\n");
    set_ac(2);
    set_weight(2);
    set_size("medium");
    set_type("armour");
}
