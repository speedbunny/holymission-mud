inherit "obj/monster";
reset(arg)     {
   object charm;
   object money;
   ::reset(arg);
   set_alt_name("the baker");
   set_name("baker");
   set_alias("man");
   set_level(10);
   set_wc(10);
   set_ac(3);
   set_hp(155);
   set_gender(1);
   set_short("The village baker");
   set_long(
       "Red of face, full of cheer and starchy foods, the village baker\n"
       + "looks at you with a twinkle in his eye, and a gleam in his moustache.\n"
   );
   set_al(150);
   set_aggressive(0);
   charm = clone_object("/wiz/stanley/obj/charm");
   move_object(charm,this_object());
   money = clone_object("/obj/money");
   money->set_money(random(75)+20);
   move_object(money, this_object());
}
