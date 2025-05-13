inherit "obj/weapon";
  reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("dagger");
  set_value(300);
  set_class(3);
  set_weight(1);
  set_short("A demonically crafted dagger");
  set_long("A dagger crafted by demons from the pits of hell...\n");
}
