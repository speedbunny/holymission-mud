inherit "obj/armour"; 

reset(arg) {
::reset(arg) ;
if (arg) return 1;

set_name("boots");
set_type("boots");
set_weight(1);
set_value(150);
set_ac(0);
set_short("boots");
set_size(3);
set_long("Tough leather boots. \n");
}
