inherit "obj/weapon";
reset(arg) {
   ::reset(arg);
   if(!arg){
   set_name("sword");
   set_short("Short Sword");
   set_long("A magnificantly crafted short sword that fits well in your\n"+
            "hand.  It has a golden handle with an emerald at the base of\n"+
            "hilt and etchings all along the blade.\n");
   set_class(16);
   set_weight(1);
   set_value(800);
}
}
