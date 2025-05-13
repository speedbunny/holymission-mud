inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("The Flaming Sword");
  set_short("The Flaming sword");
  set_long("This sword has flames running up and down it's edges!\n");
  set_alias("sword");
  set_alt_name("flaming sword");
  set_class(19);
  set_value(3000);
  set_weight(5);
}
