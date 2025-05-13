inherit "/obj/weapon";
 
reset(arg) {
    if(arg) return;
    set_name("A broken sword");
    set_alt_name("broken sword");
    set_alias("sword");
    set_short("A broken sword");
    set_long("A short sword that was used along time ago, so long that only the hilt is left\n");
    set_class(1);
    set_weight(0);
    set_value(50);
}
