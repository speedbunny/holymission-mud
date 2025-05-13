inherit "obj/monster";

reset(str) {
    ::reset(str);
    if(str) return;
    set_name("crystal elemental lord");
    set_alias("lord");
    set_race("elemental");
    set_short("Crystal elemental lord");
    set_long("This is a minor lord of the Plane of Elemental Crystal,\n"
      +"holding sway over lesser elemental beings.  It looks roughly\n"
      +"humanoid in shape.\n");
    set_level(12);
    add_money(300);
}
