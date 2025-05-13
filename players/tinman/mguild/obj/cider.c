inherit "obj/alco_drink";


reset(arg) {
  ::reset(arg);
  name="apple cider";
  alias_list = ({ "cider" });
  set_short("A bottle of apple cider");
  set_long("Maybe you should drink it.\n");
  drinking_mess=" h{fver en cider.\n";
  strength=4;
  heal_amount = 20;
  value = 20;
  }
