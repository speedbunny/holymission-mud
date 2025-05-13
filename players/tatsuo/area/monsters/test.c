/* Stolen from Matt */

inherit "/obj/monster";

reset(arg) {
  string race_name;
  ::reset(arg);
  if(arg) return;
  set_name("slave");
  set_alias("slave");
    switch(random(5)){
    case 0: {race_name="orc";break;}
    case 1: {race_name="gnome";break;}
    case 2: {race_name="hobbit";break;}
    case 3: {race_name="elf";break;}
    case 4: {race_name="wolfen";break;}
    }

  set_race(race_name);
  set_short("a weak slave");
  set_long("A scrawny and weak looking "+race_name+" slave.\n");
  set_level(10);
  set_hp(100);
  set_al(0);
  set_wc(7);
  set_ac(7);
  add_money(80);
  set_chance(5);
  set_spell_dam(25);
  set_spell_mess1("The slave bites his opponent.");
  set_spell_mess2("You are bitten by the slave!");
}

init(){
  ::init();
    add_action("testfunct","testfunct");
  }

int testfunct(){
say("monster says success!\n");
tell_object(this_player(),"monster tells you: success!\n");
return 1;
}

