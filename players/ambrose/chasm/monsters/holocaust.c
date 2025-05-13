inherit "obj/monster";

reset(arg) {
     ::reset(arg);
    if(!arg) {
       
       set_name("holocaust");
       set_race("demon");
       set_level(50);
         set_gender(2);
       set_hp(50000);
       set_al(-100);
       add_money(10000);
       set_wc(45);
       set_ac(20);
       set_aggressive(1);
       set_spell_dam(100);
       set_chance(40);
       set_dead_ob(this_object());
       set_spell_mess1("Holocaust rips out a vital organ with her blow.");
       set_spell_mess2("Holocaust rips your face with her steel gauntlet.");
       set_short("Holocaust");
       set_long("You see a beautiful woman before you that seems out of \n"
               +"place in all this horror and carnage, until you notice the \n"
               +"blood on the steel gauntlet she wears.\n");
       }
}
monster_died(ob){
          shout(this_player()->query_name()+" rips out the spine of the demon"
                                           +" Holocaust and laughs.\n");
          }
