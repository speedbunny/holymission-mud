/* checks if the player is allowed to use the boat */
inherit "obj/monster";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("viking rowar");
      set_alt_name("rowar");
      set_alias("viking");
      set_short("Viking Rowar");
      set_long("Viking Rowar is one of the lower ranking Vikings. His current \n"
             + "duty is to guard this boat and see to it that only people who have \n"
             + "the chief's permission use it. \n");
      set_level(8);
      set_race("human");
      set_gender(1);

      transfer(clone_object("/players/uglymouth/vikings/items/vikaxe"),this_object());
      transfer(clone_object("/players/uglymouth/vikings/items/viktunic"),this_object());
      command("wield axe");
      command("wear tunic");

      }
   }
