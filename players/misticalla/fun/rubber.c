inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
     set_name("condom");
     set_type("cloak");
     set_ac(0);
     set_size(3);
     set_short("A condom");
     set_long("A strong rubber condom.\n");
     set_weight(0);
     set_value(10);


}
init() {
  ::init();
}
