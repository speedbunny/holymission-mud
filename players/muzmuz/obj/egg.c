inherit "/obj/thing";
reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("easter egg");
    set_alias("egg");
    set_short("easter egg");
    set_long("This is a coloured easter egg\n");
    set_weight (1);
}
init() {
::init();
}
