/* viking boozar, the cook */
inherit "obj/monster";

void reset(int arg) {
object arm;
   ::reset(arg);

   if(!arg) {
      set_name("viking boozar");
      set_alt_name("boozar");
      set_alias("viking");
      set_short("Viking Boozar");
      set_long("Viking Boozar obviously is the cook of this camp. \n"
             + "He is a fat man with a red face, his tunic worn \n"
             + "somewhat out of line. He is cleaning some fish. \n");
      set_level(6);
      set_al(-15);
      set_race("human");
      set_gender(1);

      arm=clone_object("/players/uglymouth/vikings/items/longknife");
      arm->set_short("A longknife");
      arm->set_long("A very sharp longknife. \n");
      transfer(arm,this_object());

      transfer(clone_object("/players/uglymouth/vikings/items/viktunic"),this_object());

      command("wield knife");
      command("wear tunic");

      }
   }

