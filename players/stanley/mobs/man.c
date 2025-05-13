inherit "obj/monster";
reset(arg) {
   object money;
   ::reset(arg);
   if(arg) return;
   set_level(random(4)+8);
   set_alt_name("man");
   set_name("field hand");
   set_alias("hand");
   set_hp(((query_level()*8)+50)+random(query_level()*10));
   set_gender(1);
   set_aggressive(1);
   set_wc(random(query_level()+5));
   set_ac(random(query_level()/3)+2);
   set_short("A field hand");
   set_long(
   "A large and strong man, the field hand is enraged by your vicious\n" +
   "attack on the people of this community!\n");
   set_al(random(250)-random(250));

   money = clone_object("/obj/money");
   money->set_money(random(75)+40);
   move_object(money, this_object());
}
