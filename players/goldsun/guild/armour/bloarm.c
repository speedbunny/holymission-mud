inherit "/obj/armour";
 
reset(arg) {
::reset(arg);
if (arg) return;
 set_type("guild");
 set_name("bloarm");
 set_size(0);
}

short() { return 0; } 
long() {}

init() {
::init();
}
drop() { return 1; }

