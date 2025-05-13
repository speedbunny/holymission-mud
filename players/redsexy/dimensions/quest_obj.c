
/* quest_obj */

inherit "/obj/quest_obj"; 

void reset(int flag)
{
   ::reset(flag);
   if (flag==0)
   {
    set_name("dimension_quest");
    set_weight(21);
    set_killing(1);
    set_short_hint("Ascend to the role of Master of Dimensions");
    set_creator("redsexy");
    set_hint( "Sophillicus, the Master of the Dimensions, is looking for \n"+ 
          "someone to take over his role as the mentor of the demons.\n"+ 
          "Prove yourself worthy by learning about the seven demon\n"+ 
          "domains, taking his test and solving the final puzzle!\n" );

   }
}

     

