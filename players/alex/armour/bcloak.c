inherit "obj/armour";
 
reset(arg) {
  ::reset(arg);
    if(arg) return;
    set_name("Black cloak");
    set_alias( "cloak");
    set_short ("A black cloak");
    set_long ("A black cloak which seems to made of very good material.\n");
    set_type ("cloak");
    set_ac(0);
    set_weight(0);
    set_value(500);
}
