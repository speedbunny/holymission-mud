inherit "obj/weapon";
  reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("axe");
  set_value(300);
  set_class(5);
  set_weight(1);
  set_short("A demonically crafted axe");
  set_long("A axe crafted by demons from the pits of hell...\n");
}
