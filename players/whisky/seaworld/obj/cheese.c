inherit "obj/food";

reset(arg) {
if (arg) return;
   set_name("cheese");
   set_short("a piece cheese");
   set_long("A good smelling Ementhaler looking very tasty.\n");
   set_eater_mess("Yuuummmmm, that cheese tastes fine.\n");
   set_eating_mess(" eats a delicious Ementhaler.\n");
   set_weight(1);
   set_value(30);
   set_strength(10);
}
