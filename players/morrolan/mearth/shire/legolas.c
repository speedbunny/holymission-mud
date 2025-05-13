inherit "obj/monster";
object bow;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("legolas");
    set_alias("prince");
    set_short("Legolas the elven prince");
    set_long("This is Legolas prince of the Wood Elves. His has perfect features,\n"+
      "a slight build, and feline grace. Don't mess with him if you're not prepared.\n");
    set_level(10);
    set_race("elf");
    set_gender(1);
    set_al(100);
    set_spell_mess1("Legolas shoots you full of arrows.\n");
    set_spell_mess2("Legolas hits you over the head with his bow.\n");
    set_chance(20);
    set_spell_dam(10);
    set_wc(15);
    bow = clone_object("obj/weapon");
    bow->set_name("bow");
    bow->set_short("A beautiful bow made of elm");
    bow->set_long("A beautifully crafted elven elm bow.\n");
    bow->set_class(15);
    bow->set_weight(2);
    bow->set_value(800);
    bow->set_hit_func(this_object());
    move_object(bow, this_object());
    command("wield bow", this_object());

}
int weapon_hit(object attacker){
    if(random(100)>25)
	return 0;
    tell_room(environment(attacker), attacker->query_name()+" is filled with arrows.\n");
    return random(5);
}
