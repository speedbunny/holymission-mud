inherit "obj/monster";

reset(arg){
  if(arg) return;
  ::reset(arg);
set_alias("monster");
set_name("umber hulk");
set_aggressive(1);
set_gender(0);
set_race("umber hulk");
set_short("A looming umber hulk");
set_long("   A large looming creature with many eyes and large rock "+
           "crushing manidables looks at you with malice. You should\n"+
         "run.  NOW!!!\n");
set_level(12);

set_hp(550);
load_a_chat(5,({"You are crushed by huge manidables!",
                   "The Umber hulk steps on you!"}) );
set_ac(10);
set_al(-50);
set_chance(9);
set_spell_mess1("The Umber hulk gazes at you, You CAN'T MOVE!");
set_spell_mess2("The Umber hulk gazes at # and freezes him in his tracks!");
set_spell_dam(15);
add_money(1200);
   

}

