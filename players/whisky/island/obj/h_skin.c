inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("dragonskin");
    set_alias("skin");
    set_type("armour");
    set_ac(4);
    set_size(4);
    set_short("A heavy Dragonskin");
    set_long("The excellent armour of\n"+
             "Armonophis the confused Dragon.\n");
    set_value(8000);
    set_weight(3); 
  }
}
