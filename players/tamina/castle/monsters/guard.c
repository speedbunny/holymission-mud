/* Guard to Morgan - Modified */

inherit "obj/monster";
object mail,helmet,shield,scimitar;

#include "/players/tamina/defs.h"

void reset(int arg)
{
  ::reset(arg);
  if (!arg) 
  {
    set_name("guard");
    set_level(19);
    set_short("Morgan's Guard");
    set_long(
   "A tall undead figure that seems to have very little intelligence.\n"+ 
   "He only seems worthy to follow orders given to him by Morgan...\n"+
   "and that he does quite well...\n");
    set_al(0);
    set_aggressive(1);
    set_hp(890);
    set_wc(25);
    set_ac(13);

      mail = clone_object("obj/armour");
    helmet = clone_object("obj/armour");
    shield = clone_object("obj/armour");
  scimitar = clone_object("obj/weapon");

  mail->set_name("mail");
  mail->set_alias("chainmail");
  mail->set_short("Guard's Chainmail");
  mail->set_long(
   "A set of reasonably well-made chainmail, smithied from an unusual \n"+
   "metal, which you cannot identify.  There is a crest emblazoned on \n"+
   "the front.  It looks as though it protects well.\n");
  mail->set_weight(4);
  mail->set_size(3);
  mail->set_ac(3);
  mail->set_value(1000);
  mail->set_type("armour");

  helmet->set_name("helmet");
  helmet->set_alias("helm");   
  helmet->set_short("A Black Helmet");
  helmet->set_long("A fine helmet made out of a strange black metal.\n"+  
                   "There is a crest on the top of the helmet.\n");
  helmet->set_weight(2);
  helmet->set_value(130);
  helmet->set_ac(1);   
  helmet->set_size(3);
  helmet->set_type("helmet");

  shield->set_name("shield");
  shield->set_short("A Black Shield");
  shield->set_long("A fine shield made out of a strange black metal.\n"
                   "There is a crest printed on the front of the shield.\n");
  shield->set_weight(2);
  shield->set_value(850);
  shield->set_ac(2);
  shield->set_size(3);
  shield->set_type("shield");

  scimitar->set_name("scimitar");
  scimitar->set_alias("sword");
  scimitar->set_short("A Black Scimitar");
  scimitar->set_long(
"A wicked, curving blade, crafted out of a strange black metal\n"+
"that you do not recognise.  It has a set of runes etched along the\n"+ 
"length of the blade...\n");
  scimitar->set_weight(3);
  scimitar->set_value(2500);
  scimitar->set_read("You cannot understand the runes.\n");
  scimitar->set_class(17);

  MO(mail,TO);
  MO(helmet,TO);
  MO(shield,TO);
  MO(scimitar,TO);
  command("wear mail");
  command("wear helmet");
  command("wear shield");
  command("wield scimitar");

   }

}

