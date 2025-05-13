inherit "obj/npc";

int clones;
object w1,w2;
    
reset (arg) {
    object o;
    clones=0;
    ::reset(arg);
    if (arg) return;
    set_name("balor");
    set_alt_name("tana-ri");
//    move_object(clone_object("/players/jewel/quest/hills/dplate"),this_object());
    move_object(w1=clone_object("/players/jewel/quest/hills/fsword"),this_object());
    move_object(w2=clone_object("/players/jewel/quest/hills/demonwhip"),this_object());
    move_object(o=clone_object("/players/whisky/obj/red_bull_potion"),
                this_object());
    move_object(o=clone_object("obj/armour"),this_object());
    o->set_name("cross");
    o->set_short("a silver cross");
    o->set_long("A beautiful worked silver cross.\n");
    o->set_weight(1);
    o->set_ac(1);
    o->set_type("amulet");
    o->set_value(500);
    set_level(60);
    set_hp(query_max_hp()+1000);
    set_al(-500);
    set_ac(20);
    set_aggressive(1);
    set_wc(50);
    set_race("demon");
    set_short("Balor");
    set_size(4);
    set_long("This Tana-Ri is one of the nobles of his race. In his left\n"+
             "hand he wields a sword of flames, and in the other he's got\n"+
             "a strange looking whip, dripping of poison.\n"+
             "As you come nearer you notice the heat his body emits.\n");
    set_chance(10);
    set_spell_mess1("The demon flames his opponent");
    set_spell_mess2("You are burned by the flames around Balors body.");
    set_spell_dam(100);
    set_no_steal();
    command("wield whip",this_object());
    command("wear demonplate",this_object());
    command("wear bracers",this_object());
}

hold(ob, tim)
{
   if(random(100)<50) ::hold(ob, tim);
   ::hold(ob,0);
}

int attack()
{
   object tmp;
   int rtc;

   hands[0]=w1;
   rtc = ::attack();
   hands[0]=w2;
   rtc += ::attack();
   return rtc;
}

query_str() { return 120; }
query_dex() { return 120; }

detect_invis() { return 1; }

heart_beat()
{ 
    string x;

    ::heart_beat();
    if(query_hp()<1000 && clones<6)
    {
        switch(random(4))
        {
            case 0: x="babau"; break;
            case 1: x="chasme"; break;
            case 2: x="vrock"; break;
            case 3: x="marilith"; break;
        }
        clones++;
        say("\nBalor utters the words 'pgnw'\n");
        clone_object("players/jewel/quest/hills/"+x)->move_player(
          "BANZAI",environment(),1,"steps out of a flickering gate");
    }

    if(query_hp()<2000 && clones<4)
    {
        clones++;
        say("\nBalor utters the words 'pgnw'\n");
        clone_object("players/jewel/quest/hills/manes")->move_player(
          "BANZAI",environment(),1,"steps out of a flickering gate");
    }
}
