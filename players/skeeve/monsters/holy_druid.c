inherit "/obj/monster";

#include "/players/skeeve/area.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("priest");
    set_alt_name("holy priest");
    set_short("A holy priest");
    set_long("");
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
    set_spell_dam(48);
    set_spell_mess1("The sphinx casts a bolt at you.");
    set_spell_mess2("The sphinx shocks you with his roaring.");
  }
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
  if (ob->id("holy stuff")) {
    str += "stuff.\n";
    command("wield holy stuff");
    command("instantum illuminaris stuff");
  } else if (ob->id("holy shield")) {
    str += "shield.\n";
    command("wield holy shield");
    command("instantum illuminaris shield");
  } else if (ob->id("holy amulet")) {
    str += "amulet.\n";
    command("wear holy amulet");
    command("instantum illuminaris amulet");
  } else if (ob->id("holy robe")) {
    str += "robe.\n";
    command("wear holy robe");
    command("instantum illuminaris robe");
  }
  
  if ( present("holy stuff") && present("holy shield")
    && present("holy amulet") && present("holy robe") ) {
    str += " I have all my equipment back! so you have finished the quest!\n";
    TP->set_quest("holy_druid");
    say( TPN+" finished the quest!!!.\n", TP );
    if (!TP->query_quests("holy_druid"))
      TP->add_exp(TPL*1000);
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
