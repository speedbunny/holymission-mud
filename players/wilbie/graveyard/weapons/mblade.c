inherit "obj/weapon";
  reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("blade");
  set_value(300);
  set_class(5);
  set_weight(1);
  set_short("A demonically crafted blade");
  set_long("A blade crafted by demons from the pits of hell...\n");
}
