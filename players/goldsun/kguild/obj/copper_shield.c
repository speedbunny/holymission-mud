inherit "/obj/armour";

reset(arg){
 ::reset(arg);

if (arg) return;
set_name("copper shield");
set_alias("shield");
set_type("shield");
set_ac(1);
set_short("A knight shield");
set_long("A cooper knight shield.\n");
set_size(0);
set_value(1200);
set_weight(1);
}
