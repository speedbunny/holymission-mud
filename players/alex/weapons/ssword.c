inherit "/obj/weapon";
 
reset(arg) {
    if(arg) return;
    set_name("short sword");
    set_alias("sword");
    set_short("A short sword");
    set_long("A short sword that was just made for those who\n"+
             "are just starting out in the monster killing game. \n");
    set_class(5);
    set_weight(1);
    set_value(50);
}
 
