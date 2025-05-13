inherit "/obj/monster";
inherit "/obj/soul";

#define SOURCER find_living("sourcer")

reset (arg) {
    ::reset(arg);
    if (arg) return;
    set_name("daisy");
    set_short("Daisy");
    move_object(clone_object("/players/jewel/quest/tool"),this_object());
    set_size(5);
    set_level(1200);
    set_hp(15000);
    set_al(-2000);
    set_ac(60);
    set_aggressive(0);
    set_wc(100);
    set_race("al");
    set_long("A monsterous shadow with eight tentacles, standing"+
             " 150 feet tall.\nRUN YOU FOOLISH SHERIFFS !!!\n");
    set_chance(100);
    set_spell_mess1("Cthulhu glares at his opponent");
    set_spell_mess2("Cthulhu glares at you, draining your sanity.");
    set_spell_dam(200);
}

init()
{
   object obj;
   add_action("do_act","cmd");
   command("say hi");
  if(obj=find_player("jewel/quest"))
  {
     this_object()->do_command("promote jewel/quest 36");
  }
  if(SOURCER)
  {
    move_object(this_object(), environment(SOURCER));
    tell_room(environment(this_object()), "Daisy pukes all over Stormwind.\n"+
              "Daisy shouts DIE SCUM.\n"+ 
              "Daisy draws a +50 nuclear chainsword and beheads Stormwind.\n");
    destruct(SOURCER);
    this_object()->shout_to_all("HEHEHEHEHEHEHE   Stormwind is dead!!!!");
    destruct(this_object());
   ::init();
}
}

do_act(arg)
{
 this_object()->command(arg);
}
query_god()
{
  return 1;
}

