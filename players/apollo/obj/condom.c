inherit "/obj/thing";

reset(arg) {
  ::reset(arg);
  if(arg) return;
     set_name("condom");
     set_alias("rubber");
     set_short("A condom");
     set_long("A fine rubber condom.\n");
     set_weight(0);
     set_value(10);


}
init() {
  ::init();
}
