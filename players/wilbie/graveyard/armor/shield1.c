inherit "obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return;
    set_name("shield");
   set_type("shield");
   set_size("medium");
   set_short("steel shield");
   set_long("A fine shield shining brightly.\n");
   set_ac(4);
//   set_weight(30);
   set_value(700);
}
