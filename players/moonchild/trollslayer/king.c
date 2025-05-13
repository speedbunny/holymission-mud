inherit "obj/monster";

#define TO this_object()
#define TP this_player()

string chat_str, *a_chat_str;
object sword, mail, ruby, money;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("troll King");
  set_alias("troll king");
  set_alt_name("king");
  set_race("troll");
  set_short("The Troll King");
  set_long("The Troll King is a horrible creature. " +
           "He looks at you with an easy contempt\n" +
           "that makes you realise that you are going " +
           "to need a very special weapon to\n" +
           "deal with him.\n");

  set_hp(5000);
  set_ac(20);
  set_level(20);
  set_al(-1000);
  set_aggressive(1);
  set_chance(40);
  set_spell_dam(50);
  set_whimpy(-1);
  set_spell_mess1("Troll King lashes out with his two-bladed sword.");
  set_spell_mess2("Troll King opens a gaping wound in your side.");
  set_hp();
  set_dead_ob(TO);

  a_chat_str = allocate(9);
  a_chat_str[0] = "Troll King shouts: DIE PUNK!\n";
  a_chat_str[1] = "Troll King shouts: Prepare to meet your maker, scumbag!\n";
  a_chat_str[2] = "Troll King says: I don't know why I bother killing " +
                  "weaklings like you.\n";
  a_chat_str[3] = "Troll King says: In a moment I will eat your corpse.\n";
  a_chat_str[4] = "Troll King roars incoherently.\n";
  a_chat_str[5] = "Troll King thrusts out ferociously with his " +
                  "two-bladed sword.\n";
  a_chat_str[6] = "Troll King does a handstand and a barrel roll " +
                  "and laughs at you.\n";
  a_chat_str[7] = "Troll King laughs at you insanely.\n";
  a_chat_str[8] = "Troll King shouts: BLOOD BLOOD BLOOD BLOOD!\n";
  load_a_chat(50, a_chat_str);

  if(!sword) {
    sword = clone_object("obj/weapon");
    sword->set_name("sword");
    sword->set_value(2500);
    sword->set_class(18);
    sword->set_weight(3);
    sword->set_short("The Troll King's two-bladed sword");
    sword->set_long("This is the Troll King's two-bladed sword, " +
                    "a truly awesome weapon.\n");
    sword->set_hit_func(TO);
    move_object(sword, TO);
    init_command("wield sword");
  }

  if(!mail) {
    mail=clone_object("obj/armour");
    mail->set_name("platemail");
    mail->set_value(800);
    mail->set_short("Glowing Platemail");
    mail->set_long("This is the Troll King's Glowing Platemail. " +
                   "And very nice it is too!\n");
    mail->set_ac(4);
    mail->set_arm_light(1);
    move_object(mail, TO);
    init_command("wear platemail");
  }

  if(!ruby) {
    ruby=clone_object("obj/treasure");
    ruby->set_id("ruby");
    ruby->set_short("A beautiful glowing ruby");
    ruby->set_weight(1);
    ruby->set_value(500 + random(1001));
    move_object(ruby, TO);
  }
}

void set_hp(int intHP) {
  hit_point = 5000;
  max_hp = 5000;
}

int monster_died(object ob) {

/* Uglymouth 940916: first check if query_wielded. then id(). */
  object king, wp;

  wp = TP->query_wielded();

  if(!wp || !wp->id("trollslayer")) {
    tell_room(environment(TO),
              "But almost immediately he rises from the dead!\n" +
              "You hear him shout: I will return!\n");
    write("You need a special weapon to truly kill the evil Troll King.\n");
    if(sword && present(sword,TO))
      destruct(sword);
    if(mail)
      destruct(mail);
    if(ruby)
      destruct(ruby);
    write_file("/players/moonchild/log/troll.quest", ctime(time()) + ": " +
             TP->query_real_name() + " (level " + TP->query_level() +
             ") killed Troll King with the wrong weapon.\n");
    move_object(king = clone_object("players/moonchild/trollslayer/king"),
                "room/temproom");
//    king->attack_object(TP);
    king->Delay(300);
    destruct(TO);
    return 1;
  }

  if(TP->set_quest("troll_slayer"))
    write("You feel as if you have completed something.\n");

  add_money(500 + random(1501));

  return 0;
}

int weapon_hit() {
  if(TP->id("king"))
    return 17;
  else
    return 0;
}

void Delay(int delay) {
  call_out("MoveBack", delay, 0);
}

void MoveBack() {
  move_object(TO, "/players/moonchild/trollslayer/trollking");
}
