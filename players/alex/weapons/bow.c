 
inherit "/obj/weapon";
 
reset(arg) {
    if(arg) return;
    set_name("Masters bow");
    set_alias("bow");
    set_short("A broken bow");
    set_long("This would have been a superb weapon but as the Master\n"+
             "bowman died, he fell on it, breaking the bow beyond repair.\n");
    set_class(1);
    set_weight(1);
    set_value(150);
}
 
 
 
 
 
 
 
