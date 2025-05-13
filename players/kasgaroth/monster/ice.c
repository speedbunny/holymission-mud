inherit "obj/monster";

reset(str) {
    ::reset(str);
    if(str) return;
    set_name("ice elemental");
    set_race("elemental");
    set_short("Crystal elemental");
    set_long("This being, native to the Plane of Elemental Ice, appears\n"
      +"as nothing more than a large chunk of ice.  It chills you as you\n"
      +"stand near it.\n");
    set_level(6);
    add_money(150);
    no_steal = 1;
}
