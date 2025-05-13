
inherit "obj/armour";

reset(arg){
  ::reset(arg);
  if(arg) return;

  set_name("tattered rags");
  set_alias("rags");
  set_alt_name("robe");
  set_short("tattered rags");
  set_long(
   "A makeshift robe, made up of scraps of rags. It appears to be an \n"+
   "article of clothing common amongst peasants and paupers. It seems \n"+
   "that it will provide nearly no protection against the cold, let \n"+
   "alone an attack.\n");
  set_value(15);
  set_weight(1);
  set_ac(0);
  set_type("robe");
}
