inherit "obj/monster";
string chats;
reset(arg) {
    ::reset(arg);
    if(!arg) {
   set_name("spirit");
   set_race("undead");
   set_short("spirit");
   set_walk_limit("/players/wilbie/graveyard");
//   set_walk_chance(50);
   set_alias("wailing");
  set_long("This poor spirit seems to be feeling terrible sorrow and "+
      "anguish for some reason...  It appears to be trying to speak!!\n");
   set_level(10);
  set_al(1);
   set_ac(15);
   set_wc(1);
  if (!chats) {
  chats=allocate(9);
  chats[0]="Lost Spirit says: You must stop the evil!!\n";
  chats[1]="The Lost Spirit looks at you.\n";
chats[2]="Lost Spirit says:  This letter holds the answer!\n";
   chats[3]="The Lost Spirit wails in sorrow!\n";
chats[4]="Lost Spirit says:  The dark one is in the flames below!\n";
chats[5]="Lost Spirit says:  She will destroy the world!\n";
chats[6]="Lost Spirit reaches for your hand.\n";
chats[7]="The Lost Spirit looks around.\n";
chats[8]="The Lost Spirit sighs sadly.\n";
	}
        load_chat(30,chats);
    }

  set_spell_mess1("The spirit wails and you feel your soul freeze!!");
set_spell_mess2("You cringe in agony as the spirits wail freezes your soul!");
                 
  set_chance(20);
  set_spell_dam(10+random(40));
}

