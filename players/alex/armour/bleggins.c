inherit "obj/armour";
 
reset(arg) {
  ::reset(arg);
 
    if(arg) return;
    set_name("Black leggins");
    set_alias("leggins");
    set_short ("A pair of small black leggins");
    set_long ("A pair of tight black leggins, can you squeze into them?.\n");
    set_type ("leggins");
    set_size ("small");
    set_ac(0);
    set_weight(1); 
    set_value(200);
}
 
 
