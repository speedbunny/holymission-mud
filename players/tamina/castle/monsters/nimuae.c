/*  This is a Blank Monster  */

#include "/players/tamina/defs.h"

inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

     set_name("nimuae");
     set_short("Nimuae the Waif");
     set_long(
"This is a supernatural being, in the form of a beautiful yong lady.\n"+
"She has wispy white hair which seems to blow around her, despite any\n"+
"wind to speak of.  Her girlish features suggest that she is very young,\n"+
"but her strange waif-like figure would not deceive any ordinary person.\n"+
"She wears very thin, transparent sheets of fine silken garments, which\n"+
"seem to reveal more than they hide...\n");
     set_level(60);
     set_race("faerie");
     set_gender(2);
     set_al(500);
     set_aggressive(0);
     set_hp(8000);
     set_wc(40);
     set_ac(40);
     set_spell_mess2("Nimuae wraps her ice-cold hands around your head !!\n");
     set_spell_mess1("Nimuae turns her opponent blue !!\n");
     set_spell_dam(60);
     set_chance(29);
     add_money(2000);
     load_chat(29,
({"Nimuae says: If thou seekest Merlin, thou shalt find him in the deeper places...\n",
  "Nimuae tries to guide you along the right path.\n",
  "Nimuae the waif sings a sad lament.\n",
  "Nimuae tentatively points to the wardrobe, and says:\n"+
  "      Be careful, brave adventurer.\n",
  "Your heart leaps as you look at such a supernatural beauty.\n",
  "Nimuae says: Please help Merlin.  He is Arthur's only hope against Morgan.\n",   
  "Nimuae wishes you luck in your quest. \n" }) );

    }

}
