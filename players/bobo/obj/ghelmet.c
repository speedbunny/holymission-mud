inherit "/obj/armour";
reset(arg) {
::reset(arg);
if(!arg) {
set_name("helmet");
set_short("Gladiator helmet");
set_long("A brass helmet");
set_ac(1);
set_size(3);
set_type("helmet");
set_value(50);
set_weight(1);
}
}
