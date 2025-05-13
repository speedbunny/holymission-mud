inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("dragonskin");
    set_alias("skin");
    set_type("armour");
    set_ac(4);
    set_size(3);
    set_short("A blue dragonskin");
    set_long("The excellent armour of\n"+
             "the blue volcano Dragon.\n");
    set_value(2000);
    set_weight(2); 
  }
}
