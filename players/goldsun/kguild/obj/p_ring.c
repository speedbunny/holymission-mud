inherit "/obj/armour";

reset(arg){
 ::reset(arg);

if (arg) return;
set_name("ring of protection");
set_type("ring");
set_ac(1);
set_short("A ring of protection");
set_long("A golden ring of protection.\n");
set_value(90);
set_size(0);
set_weight(1);
}
