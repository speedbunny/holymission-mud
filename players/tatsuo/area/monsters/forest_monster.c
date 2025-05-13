/* Stolen from Matt */

inherit "/obj/monster";

reset(arg) {
  string race_name;
  ::reset(arg);
  if(arg) return;
  
  switch(random(6)){
  case 0: {
    set_name("slave");
    set_alias("slave");
    set_alt_name("monster");
    switch(random(5)){
    case 0: {race_name="orc";break;}
    case 1: {race_name="gnome";break;}
    case 2: {race_name="hobbit";break;}
    case 3: {race_name="elf";break;}
    case 4: {race_name="wolfen";break;}
    }
    set_race(race_name);
    set_short("a weak slave");
    set_long("A "+race_name+" slave who seems to have escaped the camp.\n");
    set_level(6);
    set_hp(100);
    set_al(0);
    set_wc(7);
    set_ac(7);
    add_money(300);
    set_chance(5);
    set_spell_dam(25);
    set_spell_mess1("The slave bites his opponent.");
    set_spell_mess2("You are bitten by the slave!");
    break;
  }
  case 1:{
    set_name("woodpecker");
    set_alias("woodpecker");
    set_race("bird");
    set_alt_name("monster");
    set_short("a colorful woodpecker");
    set_long("A small woodpecker in search of food.  He does not notice your presence.\n");
    set_level(random(4)+3);
    set_hp(random(100));
    set_al(0);
    set_wc(3);
    set_ac(3);
    set_chance(5);
    set_spell_dam(5);
    set_spell_mess1("The woodpecker pecks his opponent.");
    set_spell_mess2("You are pecked by the woodpecker!");
    break;
  }
  case 2:{
    set_name("squirrel");
    set_alias("squirrel");
    set_race("rodent");
    set_alt_name("monster");
    set_short("a squirrel");
    set_long("A small squirrel.  He is climbing trees in search of food.\n");
    set_level(3+random(4));
    set_hp(50+random(40));
    set_al(0);
    set_wc(7);
    set_ac(7);
    set_chance(0);
    break;
 }
  case 3:{
    set_name("fox");
    set_alias("fox");
    set_race("fox");
    set_alt_name("monster");
    set_short("a sly fox");
    set_long("A thin wiry fox in search of food.\n");
    set_level(4+random(4));
    set_hp(50+random(40));
    set_al(0);
    set_wc(random(10));
    set_ac(random(14));
    set_chance(0);
    break;
  }
  case 4:{
    set_name("frog");
    set_alias("frog");
    set_race("frog");
    set_alt_name("monster");
    set_short("a bull frog");
    set_long("A small bull frog that stares at you complacently.\n");
    set_level(1+random(4));
    set_hp(50+random(60));
    set_al(0);
    set_wc(8);
    set_ac(8);
    set_chance(0);
    break;
  }
  case 5: {
    set_name("wolf");
    set_alias("wolf");
    set_race("wolf");
    set_alt_name("monster");
    set_short("a grey wolf");
    set_long("A grey wolf who looks at you as if you are his dinner.\n");
    set_level(8+random(4));
    set_hp(80+random(40));
    set_al(0);
    set_wc(random(14));
    set_ac(random(14));
    set_chance(0);
    break;
  }
  case 6:{
    set_name("deer");
    set_alias("deer");
    set_race("deer");
    set_alt_name("monster");
    set_short("a deer");
    set_long("A brown timid looking deer.\n");
    set_level(4+random(4));
    set_hp(80+random(40));
    set_al(0);
    set_wc(random(10));
    set_ac(random(10));
    set_chance(0);
    break;
  }
  case 7:{
    set_name("rabbit");
    set_alias("rabbit");
    set_race("rabbit");
    set_alt_name("monster");
    set_short("a grey rabbit");
    set_long("A small grey rabbit that is running from the fox.\n");
    set_level(2+random(3));
    set_hp(80);
    set_al(0);
    set_wc(random(7));
    set_ac(random(7));
    set_chance(0);
    break;
  }

  case 8:{
    set_name("owl");
    set_alias("owl");
    set_race("bird");
    set_alt_name("monster");
    set_short("a spotted owl");
    set_long("This owl is resting on a nearby treelimb, just within reach.\n");
    set_level(4+random(4));
    set_hp(80+random(30));
    set_al(0);
    set_wc(random(12));
    set_ac(random(12));
    set_chance(0);
    break;
  }
  }
}






