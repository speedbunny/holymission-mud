inherit "/obj/armour";
 
reset(arg) {
::reset(arg);
if (arg) return;
 set_name("shield");
 set_short("A wooden shield");
 set_long("A shield made of wood.\n");
 set_value(150);
 set_weight(1);
 set_type("shield");
 set_size(0);
 set_ac(1);
}

init() {
::init();
}

 
