inherit "obj/npc";

int ticks;
int fl;

reset (arg) {
    ::reset(arg);
    if(environment() && environment()->id("coffin")) ticks++;
    if(ticks==2) {
        ticks=0;
        fl=666;
        set_aggressive(0);
        move_player("X#players/jewel/quest/vtower7");
    }
    if (arg) return;
    set_name("vampire king");
    set_alt_name("vampire");
    set_alias("king");
    set_level(80);
    set_hp(query_hp()+1000);
    set_al(-1000);
    set_ac(25);
    set_aggressive(0);
    set_race("greatundead");
    set_short("Vampire King");
    set_long("A dark figure with very long fangs.\n");
    set_chance(20);
    set_spell_mess1("Vampire King stares in his victims eyes");
    set_spell_mess2("Vampire King drains you");
    set_spell_dam(120);
    set_dead_ob(this_object());
    set_attacks(3);
    set_attacks_change(100);
    set_dodge(25);
    move_object(clone_object("players/jewel/quest/regring"),this_object());
    if(sizeof(explode(file_name(this_object()),"#"))>1)
        "players/jewel/quest/swords/sword1"->xxx();
    command("wear ring",this_object());
    command("wield sword",this_object());
    ticks=0;
}

monster_died(ob) {

    int i;
    object *obj;
    obj = all_inventory(this_object());
    for (i=0 ; i < sizeof(obj) ; i++) {
        if (obj[i]->query_poison_amount()) {
            destruct(obj[i]);
            i = sizeof(obj);
        }
    }

    if(environment(this_object())==find_object("players/jewel/quest/vtower9")) {
        say(this_object()->query_name()+" transforms into a cloud of gas\nand"+
          " disappears through a crack in the northern wall.\n");
    } else {
        say(this_object()->query_name()+" transfroms into a cloud of gas and "+
          "disappears.\n");
    }
    move_object(this_object(),"players/jewel/quest/vtower10");
    move_object(this_object(),
      find_object("players/jewel/quest/vtower10")->get_coffin(random(3)));
    return 1;
}

dump() { return ({ ticks, fl });  }

add_poison(a)
{ // NOPE
;
}
