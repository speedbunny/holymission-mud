inherit "/obj/monster";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_short("huorn");
    set_alias("tree");
    set_name("Evil Huorn");
    set_long(
      "The huorns are close relatives to the Ents, huge and powerful tree\n"+
      "beings. The Huorns are rather dependent for guidance, though, and\n"+
      "through neglect they become evil and twisted. While not being as\n"+
      "powerful and strong as Ents, they are a force to be reckoned with.\n"+
      "The gnarled and twisted branches and boughs are strong enough to\n"+
      "break bones and cut short your life.\n");
    set_race("huorn");
    set_level(15);
    set_ac(10);
    set_spell_mess2("The Huorn grabs you in its hands and crushes you.\n");
    set_spell_mess1(
      "The Huorn grabs "+previous_object()->query_name()+" and crushes "+
      previous_object()->query_objective()+".\n");
    set_chance(50);
    set_spell_dam(20);
    set_aggressive(1);
}
