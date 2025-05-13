inherit "obj/monster";
reset(arg) {
   object sword;
   object money;
   if(arg) return;
   ::reset();
   set_level(14);
   set_alt_name("orc");
   set_name("Orc Captain");
   set_alias("orc");
   set_ep(15000);
   set_race("orc");
   set_wc(15);
   set_ac(6);
   set_short("A large orc");
   set_long("A large, smelly, fully angered orc captain. He looks like\nhe's going to attack!\n");
   set_al(-400);
   set_aggressive(1);
   sword = clone_object("/players/stanley/obj/sword");
   move_object(sword,this_object());
   money = clone_object("/obj/money");
   money->set_money(1665);
   move_object(money, this_object());
}
