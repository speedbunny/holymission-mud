inherit "obj/weapon";
  reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("shard");
  set_value(300);
  set_class(1);
  set_weight(1);
  set_short("A demonically crafted shard");
  set_long("A shard crafted by demons from the pits of hell...\n");
}
