inherit "/obj/monster";

#include "/players/skeeve/area.h"
#include "/players/skeeve/code.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("lakmir");
    set_alt_name("Lakmir");
    set_alias("druid");
    set_short("The Druid Lakmir");
    set_long("The Druid Lakmir.\n"
           + "He is gesturing wildly and is chanting in an archaic tongue.\n");
    set_race("druid");
    set_al(200);
    set_level(75);
    set_hp(12000);
    set_sp(12000);
    set_wc(42);
    set_ac(25);
    set_chance(50);
    set_spell_dam(100);
    set_spell_mess1("Lakmir cast a spell!");
    set_spell_mess2("Lakmir hurl a lightning at you!");
    set_aggressive(0);
    set_no_steal();
    add_money(50+random (51));
    load_chat(50,({
         "Lakmir says: I am hungry!\n",
         "Lakmir say: Bring me my fishsoup!\n"
       }) );
  }
  ARMOUR("perl ring","perl_ring",this_object());
}

enter_inventory(ob) {
  string str;
  if (!(ob->id_quest("fishsoup"))) { 
    write("Lakmir says: Ugh, thanks. But I don't need it.\n"); 
    transfer(ob,this_player()); 
    return;
  } 
  if (creator(ob)!=WIZNAME) {
    log_file("QUESTS.CHEAT",this_player()->query_real_name()+" "+
              file_name(ob)+" "+ctime(time())+"\n"); 
    destruct(ob); 
    return; 
  }
  str = "Lakmir says: Thank you for the soup!";
  if (!this_player()->query_quests("fishsoup")) {
    this_player()->add_exp(this_player()->query_level()*1000);
    str +=" You finished the quest!!!.\n";
    say(capitalize(this_player()->query_name())+" finished the quest!!!.\n");
    this_player()->set_quest("fishsoup");
  }
  write (str);
  destruct(ob);
}
