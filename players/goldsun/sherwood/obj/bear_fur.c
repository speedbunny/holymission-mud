inherit "obj/armour";
reset(arg){
 ::reset(arg);
if (!arg) {
 set_name("bear fur");
 set_alias("fur");
 set_short("Brown bear fur");
 set_long("This is the hot fur from the brown bear.");
 set_ac(2);
 set_value(400);
 set_size(3);
 set_weight(2);
 set_type("armour");
}
}
