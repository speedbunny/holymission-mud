
inherit "/obj/armour";
 
reset(arg) {
  ::reset(arg);
  if(!arg) {
      set_name("red gold and green helmet");
      set_type("helmet");
      set_ac(2);
      set_short("A red gold and green helmet");
      set_long("The strong helmet of a Rastafarian Soldier.\n");
      set_value(3);
      set_weight(0);
  }
}
 
inherit "obj/soft_drink";
reset(arg) {
  ::reset(arg);
  if(arg)  return;
   name="fish tea";
   alias="tea";
   alt_name="ital fish tea";
   short_desc="A cup of very ital fish tea";
   long_desc="It looks refreshing and healthy.\n";
   strength=14;
}
