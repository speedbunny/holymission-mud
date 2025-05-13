inherit "/obj/monster";

#include "/players/skeeve/area.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("druid");
    set_alt_name("holy druid");
    set_short("A holy druid");
    set_long("A holy druid.\n");
    set_race("human");
    set_size(2);
    set_al(9000);
    set_level(40);
    set_chr(55);
    set_int(55);
    set_str(35);
    set_dex(33);
    set_hp(3000);
    set_sp(3000);
    set_wc(20);
    set_ac(9);
    set_aggressive(0);
    set_no_steal();
    set_whimpy(-1);
    set_male();
    set_chance(90);
    set_spell_dam(20);
    set_spell_mess1("The priest casts a bolt at you.");
    set_spell_mess2("The priest casts a fireball at you.");
    load_chat(5,({
       "The druid says: Oh, that nasty thiefs!\n",
       "The druid says: They have stolen my equipment!\n",
       "The druid says: Please bring back my equipment!\n",
       "The druid says: They are still in the maze!\n"
    }) );  }
}

enter_inventory(ob) {
  string str;
  if (!(ob->id_quest("holy_druid"))) { 
    write("The holy druid says: Ugh, thanks. But I don't need it.\n"); 
    transfer(ob,this_player());
    return;
  } 
  if (creator(ob)!=WIZNAME) {
    log_file("QUESTS.CHEAT",this_player()->query_real_name()+" "+
            file_name(ob)+" "+ctime(time())+"\n"); 
    destruct(ob); 
    return; 
  }
  str = "The holy druid says: Thank you for bringing back my ";
  if (ob->id("stuff")) {
    str += "stuff.\n";
    command("wield stuff");
    command("instantum illuminaris stuff");
  } else if (ob->id("shield")) {
    str += "shield.\n";
    command("wield shield");
    command("instantum illuminaris shield");
  } else if (ob->id("amulet")) {
    str += "amulet.\n";
    command("wear amulet");
    command("instantum illuminaris amulet");
  } else if (ob->id("robe")) {
    str += "robe.\n";
    command("wear robe");
    command("instantum illuminaris robe");
  }
  
  if ( present("stuff") && present("shield")
    && present("amulet") && present("robe")
    && !this_player()->query_quests("holy_druid")) {
    str += " I have all my equipment back so you have finished the quest!\n";
    this_player()->set_quest("holy_druid");
    say(capitalize(this_player()->query_name())+" finished the quest!!!.\n", this_player() );
    this_player()->add_exp(this_player()->query_level()*1000);
    clear_inventory();
  }
  write(str);
}

clear_inventory() {
  object ob,next;
  command ("remove all");
  for (ob = first_inventory(this_object());ob;ob=next) {
    next = next_inventory(ob);
    destruct(ob);
  }
  local_weight = 0;
}
