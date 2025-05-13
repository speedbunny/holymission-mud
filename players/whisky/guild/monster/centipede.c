
/* centipede */

inherit "/obj/monster";

void reset(int flag)
{
  object ob;

     ::reset(flag);
     if (flag == 0)
     {
        set_name("centipede");
        set_race("centipede");
        set_ac(1);
        set_wc(1);
        set_hp(5);
        set_level(1);
        set_dex(1);
        set_str(1);
        set_whimpy(80);
        
        ob = clone_object("/obj/food");
        ob->set_name("centipede steak");
        ob->set_alias("steak");
        ob->set_amount(1);
        ob->set_value(5);
        move_object(ob,this_object());
     }
}

void init()
{
     ::init();
}


mixed attack()
{
      if (::attack() && !random(2))
      {
          ::attack();
          return 1;
      }
   return 0;
}
       

