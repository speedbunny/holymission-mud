inherit "/obj/thing";
reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name ("cloverleaf");
    set_alias ("cloverleaf");
    set_short("cloverleaf");
    set_long("This is a cow`s milk\n");
    set_weight (1);
}
init() {
::init();
}
