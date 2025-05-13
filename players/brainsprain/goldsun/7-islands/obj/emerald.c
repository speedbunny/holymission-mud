inherit "/obj/treasure";

void reset(int i){
 ::reset(i);
 if (i) return;
 set_name("emerald");
 set_alias("rock");
 set_alt_name("special_rock_070295");
 set_short("A small emerald");
 set_long(
"A small green emerald which appears to have been carved with exquisite "+
"precision.  Some of the edges have been delicately traced with gold, enhancing "+
"both the value and beauty of this wonderful gem.\n");
 set_weight(1);
 set_value(30000);
}

