
/* quest_obj */

inherit "/obj/quest_obj"; 

void reset(int flag)
{
   ::reset(flag);
   if (flag==0)
   {
    set_name("guineapig");
    set_weight(17);
    set_killing(2);
    set_short_hint("Find the Guineapig and return it to the girl");
    set_creator("muzmuz");
    set_hint(
    "Unluckily the girl had lost its guineapig. Find it and bring\n"+
    "it back to her before her parents come home.\n");
   }
}

     
