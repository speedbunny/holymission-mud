inherit "/obj/armour";
reset(arg) {
   ::reset(arg);
   if(!arg) {
   set_name("shield");
   set_short("A small shield");
    set_long("A brightly polished silver shield with a ring of etchings on\n"+
             "the outside rim framing a fist that is in the center.\n");
   set_ac(2);
   set_type("shield");
   set_value(250);
   set_weight(1);
}
}
