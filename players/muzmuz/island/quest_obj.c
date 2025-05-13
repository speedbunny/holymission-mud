
/* quest_obj */

inherit "/obj/quest_obj"; 

void reset(int flag)
{
   ::reset(flag);
   if (flag==0)
   {
    set_name("sprite_quest");
    set_weight(20);
    set_killing(8);
    set_short_hint("Find the sprite and find out what to do with it");
    set_creator("muzmuz");
    set_hint(
  "Unluckily the Zonk on the island of death had lost his valueable sprite.\n"+
  "It is your duty to find it and to return it to its owner.\n");
   }
}

     
