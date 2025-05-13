/* One of the villagers protecting the village eldest */
inherit "obj/monster";

void reset(int arg) {
object knife;
  ::reset(arg);

   if(!arg) {
      set_name("villager");
      set_alias("elder");
      set_short("A villager");
      set_long("He's just a man who makes his living from fishing and doing \n"
             + "the necessary jobs around his house. But since the invasion \n"
             + "he is more than willing to actively protect all he has left. \n"
             + "And for now that specially seems to be the old woman. \n");
      set_level(4);
      set_al(100);
      set_aggressive(0);
      set_race("human");
      set_gender(1);

      knife=clone_object("/players/uglymouth/vikings/items/longknife");
      knife->set_long("It's commonly used for cleaning fish, but it makes a decent weapon too. \n");
      transfer(knife,this_object());
      command("wield knife");

      }
   }
