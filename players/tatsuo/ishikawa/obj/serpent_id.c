inherit "obj/treasure";


   reset(arg)  {
     if(arg) return;
     set_id("serpent_id");
     set_value(0);
     set_weight(0);
     }

    query_quest_obj()
   {return 1;
  }
