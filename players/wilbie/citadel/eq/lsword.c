inherit "obj/weapon";
  reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("sword");
  set_alt_name("longsword");
  set_value(300);
  set_class(12);
  set_weight(3);
  set_short("A Citadel Broadsword");

  set_long("A finely crafted longsword from the Citadel.\n");
}
