inherit"obj/weapon";
reset(arg){
    ::reset(arg);
    if (arg) return;
    set_name("mace of doom");
    set_alias("colmace");
    set_short("Mace");
    set_class(30);
    set_long("A mace with spikes on it, very useful for bashing people to pulp.\n");
    set_value(1000);
    set_weight(20);
}
init(){
    ::init();
}
