inherit "obj/armour";

reset (arg) {
  ::reset(arg);
  if(!arg) {
    set_name("cloak");
    set_ac(1);
    set_weight(1);
    set_value(10000);
    set_short("Vampire cloak");
    set_long("A dark cloak.\n");
    set_type("cloak");
  }
}

drop() { return 1; }

get() { return (this_player()->query_immortal()); }

query_mage_wear() { return 1; }
