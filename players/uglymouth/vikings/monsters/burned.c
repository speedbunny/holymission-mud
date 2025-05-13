/* A burned man in the village square holds some information */
inherit "obj/monster";

void reset(int arg) {
  ::reset(arg);

   if(!arg) {
      set_name("burned man");
      set_alias("man");
      set_short("A badly burned man");
      set_long("Through the remains of his fisherman's clothing, you see various large \n"
             + "burns. The man is gasping for breath and not far away for death. But \n"
             + "when he sees you new hope enters his mind. \n");
      set_level(4);
      set_al(100);
      set_aggressive(0);
      set_race("human");
      set_gender(1);
      set_ep( 1 );

      load_chat(15,
               ({"The man says: They are only afraid of their gods...aarrgg! \n",
                 "The man groans: Aaaaahhh! It hurts. Help me. \n",
                 "The man almost loses consciousness. \n",
                 "The man says: If only the mermaid would be seen again. She's our symbol, our help. \n",
                 "The man groans: The vikings came...fffhh...plundered the village... \n",
                 "The man says: Those cursed vikings set our good village on fire...aie! \n",
                 "The man says: Now they've made camp just south of the village. \n",
                 "The man says: Please help! We need you to extinguish this fire.\n",
                 "The man sighs: Usch...they're too strong! \n", }));

      }
   }
