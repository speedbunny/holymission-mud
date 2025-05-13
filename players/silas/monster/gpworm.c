
inherit"obj/monster";
reset(arg) {
object coins;
object treasure;
::reset(arg);
if(arg) return;
set_name("Giant purple worm");
set_alias("worm");
set_short("Giant purple worm");
set_long(
"This purple worm looks just like the others you've seen in this maze\n"
+ "except for the fact that it's about ten times larger. It also seems to \n"
+ "have the task of preventing anyone from passing the archway which it\n"
+ "is guarding. One other important difference between this worm and its\n"
+ "smaller relatives is that it doesn't wait to find a corpse if there's\n"
+ "fresher meat around...\n");
set_level(20);
set_race("worm");
set_al(-200);
set_wc(20);
set_aggressive(1);
set_chance(33);
set_spell_dam(40);
set_spell_mess1("The worm spits acid into its attacker's face.");
set_spell_mess2("The worm spits acid into your face, burning you badly.");
set_random_pick(100);
coins = clone_object("obj/money");
coins->set_money(2000);
transfer(coins,this_object());
treasure = clone_object("/players/silas/obj/jade");
if(treasure) move_object(treasure,this_object());
}
init() {
 ::init();
 add_action("south","south");
}

south() {
   write("The giant purple worm slithers in front of the archway, effectively\n"+
         "blocking it.\n");
   return 1;
}


