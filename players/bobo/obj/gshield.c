inherit "/obj/armour";
reset(arg) {
::reset(arg);
if(!arg) {
set_name("shield");
set_short("Gladiator shield");
set_long("A very large, heavy golden shield.");
set_ac(3);
set_type("shield");
set_value(200);
set_weight(2);
}
}
