inherit "room/room";

#include "/players/skeeve/area.h";

reset(arg) {
  if (!arg) {
    set_light(1);
    short_desc = "Hill";
    long_desc = "A high mountain. A dragon lives here.\n";
    dest_dir =  ({
        LAND + "hillside1", "down"
        });
  }
  create_dragon();
}

create_dragon()  {
   object dragon, armour, diamond;
   
   if (!present("dragon"))  {
      dragon=clone_object("obj/monster");
      
      dragon -> set_name("dragon");
      dragon -> set_alias("red dragon");
      dragon -> set_short("A big purple dragon");
      dragon -> set_long("It's a big purple dragon. If she is as strong as she is big you'll be in big trouble!\n");
      dragon -> set_race("dragon");
      dragon -> set_level(40);
      dragon -> set_hp(6000);
      dragon -> set_sp(6000);
      dragon -> set_al(-300);
      dragon -> set_wc(25);
      dragon -> set_ac(15);
      dragon -> set_chance(30);
      dragon -> set_gender(2);
      dragon -> set_spell_dam(40);
      dragon -> set_spell_mess1("The dragon breathes fire!");
      dragon -> set_spell_mess2("The dragon breathes fire at you!");
      dragon -> set_aggressive(0);
      dragon -> set_no_steal();
      dragon -> wimpy(-1);
      dragon -> set_size(5);
       
      transfer(armour = clone_object("obj/armour"),dragon);
      armour -> set_name("scalemail");
      armour -> set_alias("mail");
      armour -> set_type("armour");
      armour -> set_ac(5);
      armour -> set_short("Dragon scalemail");
      armour -> set_long("Its a heavy, expensive full body armour.\n"+
                         "Its made of the scales of a purple dragon.\n");
      armour -> set_value(2000);
      armour -> set_weight(5);
      armour -> set_size(5);
      command("wear scalemail",dragon);

      transfer(diamond = clone_object("obj/treasure"),dragon);
      diamond -> set_id("diamond");
      diamond -> set_short("A big transparent diamond");
      diamond -> set_long("Its a wonderful diamond. How much would it be worth?\n");
      diamond -> set_value(500+random(1001));
      diamond -> set_weight(2);
      
      transfer(dragon,this_object());
     }
}
