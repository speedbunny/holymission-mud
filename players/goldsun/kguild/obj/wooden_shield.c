inherit "/obj/armour";

reset(arg){
 ::reset(arg);

if (arg) return;
set_name("wooden shield");
set_alias("shield");
set_type("shield");
set_ac(1);
set_short("A knight shield");
set_long("A wooden knight shield.\n");
set_size(0);
set_value(600);
set_weight(1);
}
