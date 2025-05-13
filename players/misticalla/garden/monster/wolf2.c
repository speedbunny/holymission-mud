inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;

    set_name("wolf");
    set_short("A big wolf");
    set_long("A big aggressive wolf.\n");
    set_level(3);
    set_size(2);
    set_race("animal");
    set_aggressive(1);
    set_spell_mess1("G RRRRrrrrrrr");   
    set_spell_mess2("S c h n a p .....the wolf bites you in your arm");
    set_chance(80);
    set_spell_dam(4);
    move_object(clone_object("players/misticalla/garden/obj/teeth"),
    this_object());
    init_command("wield teeth");
}

