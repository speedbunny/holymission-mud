inherit "/obj/armour";
reset(arg) {
::reset(arg);
if(!arg) {
set_name("armour");
set_short("Gladiator armour");
set_long("A very bulky looking brass breast plate.");
set_ac(3);
set_size(3);
set_type("armour");
set_value(200);
set_weight(2);
}
}
