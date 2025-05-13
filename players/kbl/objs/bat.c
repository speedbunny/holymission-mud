/* Random Bat */

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_name("bat");
    set_level(8);
    set_alias("bat");
    set_race("bat");
    set_gender(random(2));
    set_short("Cave bat");
    set_long("A foot long brown cave bat. Has red eyes and sharp yellow\n"+
             "teeth. The wings are semi-transparent.\n");
    set_chance(2);
    set_bat();
    set_spell_mess1("Bat flaps its wings at you!");
    set_spell_mess2("Bat scratchs you!");
    set_spell_dam(10);
  }
}

init()
{
  ::init();
}

set_bat()
{
    set_ac(5);
    set_wc(6);
    set_aggressive(random(2));
    set_whimpy();
    set_move_at_reset();
    load_chat(8,({
        "Bat flutters around in front of your face!\n",
        "A bat squeeks as it flies overhead\n",
        "Something flies quickly past your left ear!\n",
        "Something flies very close to your right ear!\n",
        "A bat flutters around near your right ear!\n",
        "A bat flutters around near your left ear!\n",
                  }));
}
