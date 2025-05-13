inherit "obj/weapon";
  reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("spear");
  set_value(300);
  set_class(4);
  set_weight(1);
  set_short("A demonically crafted spear");
  set_long("A spear crafted by demons from the pits of hell...\n");
}
