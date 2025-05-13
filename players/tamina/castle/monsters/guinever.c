/*  This is Queen Guinever  */

#include "/players/tamina/defs.h"

inherit "obj/monster";
 object ring,circlet;

reset(arg) {
  ::reset(arg);
  if(!arg) {

     set_name("queen Guinever");
     set_alt_name("queen");
     set_alias("guinever");
     set_short("Queen Guinever");
     set_long(
  "A beautiful young lady, with a golden circlet resting lightly\n"+
  "on her soft, shoulder-length golden hair.  You think her face \n"+
  "would be bright and show her inner exuberance, but for the sorrow\n"+
  "and loss evident in her pure, honey complexion.\n");
     set_level(25);
     set_race("human");
     set_gender(2);
     set_al(850);
     set_aggressive(0);
     set_wc(27);
     set_ac(18);
     set_spell_mess2("Queen Guinever strikes a surprisingly vicious blow!\n");
     set_spell_mess1("Queen Guinever strikes a surprisingly vicious blow!\n");
     set_spell_dam(30);
     set_chance(5);
     add_money(2500);
     load_chat(13,
  ({"Queen Guinever sobs uncontrollably.\n",
    "The Queen pines for her lost husband.\n",
    "The Queen says: If thou wilt help me, thou must seek Merlin.\n"+
    "	  	     He can aid thee in Camelot...\n",
    "Guinever says: Help the Round Table find the Grail.\n",
    "Guinever says: Where has my love gone?  Can thou bring him back?\n",
    "The Queen says: The castle is full of hidden passages, and secret dangers.\n",
    "Guinever says: Beware the witch, Morgan, and her traitorous son.\n"+
    "               They art a formidable pair...\n",
    "Queen Guinever cries sadly.\n" }) );

  ring    = CLO ("obj/armour");
  circlet = CLO ("obj/armour");

  ring->set_name("gold ring");
  ring->set_type("ring");
  ring->set_short("Guinever's Ring");
  ring->set_long(
   "A small, golden ring that glows with a soft light.\n"+
   "There is a script inlaid on the inside of the band.\n");
  ring->set_value(750);
  ring->set_weight(2);
  ring->set_size(3);
  ring->set_ac(1);
  ring->set_light(1);

  circlet->set_name("golden circlet");
  circlet->set_alias("circlet");
  circlet->set_type("helmet");
  circlet->set_short("Guinever's Circlet");
  circlet->set_long(
    "A delicate, circlet made of folded gold, by the finest \n"+
    "craftsmen in all of the realm.\n"); 
  circlet->set_value(1000);
  circlet->set_weight(2);
  circlet->set_size(3);
  circlet->set_ac(1);
  circlet->set_light(1);

  MO (ring, TO);
  MO (circlet, TO);
  command("wear ring");
  command("wear golden circlet");

    }

}
