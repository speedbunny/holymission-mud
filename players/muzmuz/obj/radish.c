inherit "/obj/thing";
reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name ("radish");
    set_alias ("milk");
    set_short("radish");
    set_long("This is a cow`s milk\n");
    set_weight (1);
}
init() {
::init();
}
