inherit "/obj/thing";

reset(arg) {
  ::reset(arg);
  if(arg) return;
     set_name("Table");
     set_alias("table");
     set_short("Stone Table");
     set_long("A table made of marble.\n");
     set_weight(200);
     set_value(100);


}
init() {
  ::init();
}
