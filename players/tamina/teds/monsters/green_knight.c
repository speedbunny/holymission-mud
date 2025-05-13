inherit "obj/monster";

object mail;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return 0;

    set_name("green knight");
    set_alias("knight");
    set_gender(1);
    set_race("human");
    set_long("This Knight is clad in green and wears green platemail.\n"+
	     "He looks very well protected, and very competent in armed combat.\n");
    set_level(17);
    set_hp(1500);
    set_al(-500);
    set_ac(9);
    set_wc(25);
    set_aggressive(1);
    add_money(150 + random(301));
    load_a_chat(30,
     ({"The Green Knight says: Thou canst not defeat me!!\n",
       "The Green Knight says: Avast, ye swine!!\n",
       "Your swipe rebounds of the Green Knight's Platemail!!\n",
       "The Green Knight nimbly avoids your poor attempts to attack him.\n",
       "The Green Knight laughs scornfully at your inability to hurt him.\n"}) );

  mail = clone_object("/obj/armour");

  mail->set_id("olive green platemail");
  mail->set_name("Olive Green Platemail");
  mail->set_alias("platemail");
  mail->set_type("armour");
  mail->set_short("Olive Green Platemail");
  mail->set_long("This is a fine set of beautifully crafted armour.\n"+
	 	 "It is made out of some strange, but very rigid material.\n"+
		 "You think it is very protective.\n");
  mail->set_value(2000);
  mail->set_weight(6);
  mail->set_ac(4);

  transfer(mail, this_object());
  command("wear platemail");

}
