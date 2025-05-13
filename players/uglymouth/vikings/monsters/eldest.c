/* The village eldest is a woman who knows much */
inherit "obj/monster";
object medal;

void reset(int arg) {
  ::reset(arg);

   if(!arg) {
      set_name("village eldest");
      set_alias("eldest");
      set_alt_name("elder");
      set_short("The village eldest");
      set_long("The village eldest is the woman from the painting, but older, \n"
             + "much older. She wears a long yellowish skirt and a green ribbon \n"
             + "holds her white hair in a long tail. Her smile is fragile and \n"
             + "her eyes show the experience and wisdom of many years. \n");
      set_level(4);
      set_al(100);
      set_aggressive(0);
      set_race("human");
      set_gender(2);
      set_dead_ob(this_object());

      transfer(clone_object("/players/uglymouth/vikings/questdir/medallion"),this_object());
      command("wear medallion");
      }
   }

void init() {
   ::init();
   add_action("greet","bow");
   add_action("greet","shake");
   add_action("greet","hug");
   }

int greet(string str) {
object med;
   if(str!="eldest" && str!="village eldest") return 0;
   if(!present("the village medallion of symria",this_object())) return 0;
   if(("/players/uglymouth/vikings/geiser")->query_hero() == this_player()->query_real_name()) {
      tell_room(environment(this_object()),"The village eldest says: Welcome, " + capitalize(this_player()->query_real_name())
         + " my friend, welcome indeed. \n"
         + "My feelings have forwarned me of your coming. You are the one that saved \n"
         + "our village from the fire. A thousand thanks for this miracle. \n"
         + "But we still have one big problem: if the vikings stay in their nearby camp, \n"
         + "the village will soon be on fire again. Please be our Champion in this \n"
         + "struggle and chase the vikings away for good. Here, take this medallion as \n"
         + "a token if you will help us. It will certainly aid you in your quest. \n");
      med=present("the village medallion of symria",this_object());
      if(!this_player()->add_weight(med->query_weight())) {
         write("The eldest says: Oh, but I see you cannot carry more.\n"
            + "I will keep the medallion until you can.\n");
         return 1;
         }
      command("remove medallion");
      move_object(med,this_player());
      this_player()->add_weight(med->query_weight());
      return 1;
      }
   return 0;
   }

monster_died() {
object ob;
   if(ob = present("the village medallion of symria")) {
      tell_room(environment(this_object()),"With her last power the village eldest destroys her medallion.\n");
      destruct(ob);
      return 0;
      }
   }
