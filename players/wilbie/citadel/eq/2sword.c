inherit "obj/weapon";
  reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("sword");
  set_value(300);
  set_class(5);
  set_weight(3);
  set_short("A Citadel Broadsword");

  set_long("A finely crafted two-handed sword from the Citadel.\n");
}
