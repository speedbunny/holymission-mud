

#define MSG "The ugly Zonk says: " 

inherit "obj/monster";
  
object hornsword;
object mail;

void reset(int arg) 
{
  ::reset(arg);
  if (arg) return;
  set_name ("zonk");
  set_alt_name("ugly zonk");
  set_race ("dwarf");
  set_short (query_name());
  set_long("An ugly Zonk. It is hard to find out what it is. \n");
  load_chat(20,
  ({ 
     MSG+"where is my Sprite ?\n",
     MSG+"have you seen it ?\n",
     MSG+"I badly need my sprite back !\n",
     MSG+"I think it got lost in the dunes.\n",
     MSG+"I looked yesterday for it, but it wasn't there anymore.\n",
     MSG+"please bring back my sprite !\n",
     "The ugly Zonk sniffs sadly.\n",
  }));
  set_level(27);
  set_dex(20);
  set_int(5);
  set_str(5);
  add_money (1000);  
 
  hornsword = clone_object ("/players/muzmuz/obj/hornsword");
              move_object (hornsword,this_object());
  init_command("wield hornsword");
  mail      = clone_object ("/players/muzmuz/obj/mail");
              move_object (mail,this_object());
  init_command("wear mail");
  init_command("wield sword");
}

void enter_inventory(object ob)
{
   if (ob->id("sprite"))
   {
      if (!ob->query_sprite())
      {
         command("say this is not my sprite, do you think I am stupid ???");
         call_out("throw_fool",1,this_player());
         return;
      }
      destruct(ob);
      command("say thank you, you brought back my sprite !");
      this_player()->set_quest("sprite_quest");
      return;
   }
   command("say keep your stuff, I am no beggar !");
   command("give "+ob->query_name()+" to "+this_player()->query_name());
   return;
}

void throw_fool(object tp)
{
    tell_object(tp,
                "Zonk grabs you and throws you out of the hole, far away\n");
    this_player()->move_player(
               "thrown away by Zonk#players/patience/tree_city/bridge4");
    return; 
}


   

