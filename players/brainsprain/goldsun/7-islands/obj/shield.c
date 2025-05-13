inherit "obj/armour";

void reset(int i){
 ::reset(i);
 if (i) return;
 set_name("shield");
 set_type("armour");
 set_short("A shield");
 set_size(2);
 set_long(
"This shell is from an enormous lobster.  It is so large that you might be able "+
"to use it as a shield.  In fact, a natural loop on the inside would be perfect "+
"to use as a handle.\n");
 set_value(30);
 set_ac(1);
 set_weight(1);
}
