inherit "/obj/weapon";
 
reset(arg) {
    if(arg) return;
    set_name("sword");
    set_alias("sword");
    set_short("Knight's sword");
    set_long("This is the sword of the late last Crusader.\n");
    set_class(15);
    set_weight(5);
    set_value(2000);
}
