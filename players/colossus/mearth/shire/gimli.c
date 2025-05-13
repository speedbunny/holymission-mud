inherit "obj/monster";
object axe, shield;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("gimli");
    set_alias("warrior");
    set_short("Gimli the dwarven warrior");
    set_long("Gimli, son of Gloin. Fearless warrior of the Iron Mountains.\n"+
      "He's no pushover and shouldn't be attacked by weaklings.\n");
    set_level(10);
    set_race("dwarf");
    set_size(2);
    set_gender(1);
    set_al(100);
    set_spell_mess1("Gimli shield bashes you in the kneecaps.\n");
    set_spell_mess2("Gimli headbutts you in the crotch.\n");
    set_chance(20);
    set_spell_dam(10);
    set_wc(15);
    axe = clone_object("obj/weapon");
    axe->set_name("axe");
    axe->set_short("A mithril axe");
    axe->set_long("A beautifully crafted dwarven mithril axe.\n");
    axe->set_class(15);
    axe->set_weight(2);
    axe->set_value(800);
    axe->set_hit_func(this_object());
    shield=clone_object("obj/armour");
    shield->set_name("shield");
    shield->set_short("An iron shield");
    shield->set_long("A sturdy round iron shield most commonly used by dwarves.\n");
    shield->set_ac(1);
    shield->set_value(350);
    shield->set_type("shield");
    shield->set_size("any");
    shield->set_weight(1);
    move_object(axe, this_object());
    move_object(shield, this_object());
    command("wield axe", this_object());
    command("wear shield", this_object());

}

int weapon_hit(object attacker){
    if(random(100)>25)
	return 0;
    tell_room(environment(attacker), attacker->query_name()+" is hacked to pieces.\n");
    return random(5);
}
