 
inherit "obj/armour";
 
reset(arg) {
  ::reset(arg);
 
    if(arg) return;
    set_name("Elven chainmail");
    set_alias("platemail");
    set_short ("A elven chainmail");
    set_long ("A shiny chainmail of elven make fit for a king.\n");
    set_type ("armour");
    set_ac(5);
    set_weight(3);
    set_value(9000);
}
 
