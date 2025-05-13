inherit "obj/npc.c";

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("ottocar");
    set_alt_name("fighter");
    set_race("fighter-god");
    set_alias("otto");
    set_short("ottocar");
    set_long("This is Ottocar a fighter-god and famous for\n" +
             "slaying everything he could get. Now he has seen\n" +
             "you and you can be sure that you will die.\n");
    set_gender(1);

    set_level(30);
    set_hp(4500);
    set_attacks_change(100);
    set_attacks(4);    

    set_al(-200);
    set_aggressive(1);
    add_money(4000);

    set_spell_mess2("SPLOP ! He pushed his suction stick onto you and hit you hard...");
    set_spell_mess1("SPLOP ! He pushed his suction stick onto you and hit you hard...\n");
    set_chance(35);
    set_spell_dam(100);

    move_object(clone_object("/players/beardy/walhalla/obj/suctionst"),this_object());
    init_command("wield stick");
  }
}
