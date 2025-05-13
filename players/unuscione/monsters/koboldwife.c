inherit "obj/monster";
   object dress,hoopak;
reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("wife");
   set_alt_name("kender");
   set_ep(150);
   set_level(7);
   set_ac(4);
   set_hp(250);
   set_wc(2);
   set_size(2);
   set_gender(0);
   add_money(500);
   set_race("kender");
   set_short("The Mayor's wife");
   set_long("An short, ugly kender in a dress with a fake left eye\n");
   set_aggressive(0);
   hoopak=clone_object("/players/exos/weapons/hoopak2");
   dress=clone_object("/players/exos/armour/dress");
   move_object(dress,this_object());
   move_object(hoopak,this_object());
   command("wield hoopak");
   command("wear dress");
   return;
}
