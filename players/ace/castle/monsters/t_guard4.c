inherit "obj/monster.c";

object weapon, armor;

reset(arg)
{
  ::reset(arg);
  set_level(18);
   set_aggressive(0);
   set_ac(12);
   set_al(-500);
   set_name("Guard");
   set_alt_name("guard");
   set_race("human");
   set_wc(15);
   set_short("A tall, burly Castle Guard");
   set_long("Guard of Ace's Castle.\n" +
            "He is very big, and looks very strong.\n"
           );
   weapon = clone_object("/players/ace/castle/weapons/sword.c");
   move_object(weapon, this_object());
    command("wield sword", this_object());
   armor = clone_object("/players/ace/castle/armor/chainmail.c");
   move_object(armor, this_object());
   command("wear chainmail", this_object());
}
