inherit "room/room";
#define SLAYER "/players/kbl/objs/slayer"
object last_solved;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "An altar room";
    long_desc = "Yellow moss gives off enough light so that you can see.\n"+
                "A small altar sits in the center of the room. Strange\n"+
                "symbols can be seen on the altar.\n";
    dest_dir = ({
                 "/players/kbl/dungeon/dun15","east",
                });
    items = ({
              "yellow moss","It glows with its own light",
              "altar","Small altar with symbols carved into its base",
              "symbols","They translate as: Lizards and Bears rule Holy Mission\n"+
                       "but a lizard's skin is easier to sacrifice especially\n"
+
                        "if you have the heart of a black bear",
              "room","You are in it just look",
             });
  }
}

init()
{
  ::init();
  add_action("sac","sacrifice");
  add_action("search","search");
  add_action("tellus","kbl");
}

tellus(str)
{
  if(!str)
   return;
  if(this_player()->query_real_name() == "kbl")
  {
   if(last_solved)
   {
    tell_object(this_player(),"Last solved = "+last_solved->query_name()+"\n");
    return 1;
   }
   else
   {
     tell_object(this_player(),"No one has solved it yet.\n");
     return 1;
   }
  }
}

sac(str)
{
  object ob,ob2;

  if(!str)
  {
    tell_object(this_player(),"Sacrifice what??\n");
    return 1;
  }
  switch(str)
  {
    case "lizard skin on altar":
         ob = present("lizard skin",this_player());
         ob2 = present("blackheart",this_player());
         if(last_solved == this_player())
         {
           tell_object(this_player(),"You already did this! Let someone else\n"+
                       "have the pleasure.\n");
           return 1;
         }
         if(present("slayer",this_player()))
         {
           tell_object(this_player(),"You have a beautiful Any slayer sword!\n")
;
           return 1;
         }
         if(ob && ob2)
         {
           if(transfer(clone_object(SLAYER),this_player()))
           {
             write("You carry too much. Drop something first.\n");
             return 1;
           }
           tell_object(this_player(),"You sacrifice the lizard's skin on the"+
                      "altar.\nYou see a beautiful sword fly out of nowhere "+
                      "and land in your hand.\n"+
                      "It forces you to wield it.\n");
           tell_object(this_player(),"You have the AnySlayer, BUT you have\n"+
                      "not solved the AnySlayer quest. The quest is solved\n"+
                      "on the Parallel Plane of Chaos and you can only get\n"+
                      "there IF you listen to the Ole man on the cliff.\n");
           last_solved = this_player();
           destruct(ob);
           destruct(ob2);
           command("wield sword",this_player());
           return 1;
         }
         if(!ob || !ob2)
          tell_object(this_player(),"You missing a sacrificial element.\n");
         return 1;
    default:
        write("Sacrifice what on what??\n");
        return 1;
  }
}

search(str)
{
  if(!str)
  {
    tell_object(this_player(),"Search what??\n");
    return 1;
  }
  switch(str)
  {
    case "room":
    case "altar":
         tell_object(this_player(),"You find nothing here worth bothering"+
                     " about.\n");
         return 1;
  }
}
