/* A real one. You'll love her. */
inherit "obj/monster";

void reset(int arg)   {
   ::reset(arg);

   if(!arg)   {
   set_name("a beautiful mermaid");
   set_level(2);
   set_al(50);
   set_alias("mermaid");
   set_short("A beautiful mermaid");
   set_long("You immediately fall in love with her. She sings so sweet\n");
   set_gender(2);
   set_wc(4);
   set_ac(4);
   set_aggressive(0);
   set_spell_mess1("That high note hurt your ears, but it sounds lovely");
   set_spell_mess2("The mermaid sings so lovely it breaks your heart");
   set_chance(60);
   set_spell_dam(10);

   load_chat(33,
            ({"The mermaid sings: 'Lift the anchor' sounded like hell at departure. \n",
              "The mermaid sings: The family at home never knew if they'd see their men again. \n",
              "The mermaid sings: Third mates always were the scapegoats aboard, for crew and officers. \n",
              "The mermaid sings: Green like grass the weaker ones hung aside during heavy storms. \n",
              "The mermaid sings: Rock seafloor is now the last bed for the many unlucky ones. \n",
              "The mermaid sings: In storms many gods were prayed to, to relieve them of this hell. \n",
              "The mermaid sings: The rations were low and so was the men's spirit if disease broke out. \n",
              "The mermaid sings: Pool your money and gamble was all the entertainment sailors had. \n",
              }));

   }
}
