/* KBL's castle Entrance chamber */
inherit "room/room";
object tps;
object tpd;
object tpf;
int found_panel;
int found_sec;
int num_s,num_d,num_f;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    num_s = 4;
    num_d = 4;
    num_f = 4;
    found_sec = 0;
    found_panel = 0;
    set_light(2);
    short_desc = "Kbl's Entrance chamber";
    long_desc = "Paintings cover the walls of this entrance chamber. Antique\n"+
                "white walls contrast with the light blue ceiling. A large\n"+
                "oak table fills the center of this rectangular room, but no\n"+
                "chairs. The room smells of incense and you see a decanter\n"+
                "hanging in the northeast corner. You feel the power of the\n"+
                "royality that must have lived here for generations. Minds\n"+
                "not closed. Thoughts are free. A stairway leads up in east\n"+
                "wall and a blue shimmering portal is on the west wall. To\n"+
                "the north is the dimension door to Kbl's private chambers\n"+
                "and south are the doors to the corridor. There is a plaque\n"+
                "on the west wall and a sign hanging above the table. The\n"+
                 "floor is marble perfectly inlaid with silver clovers.\n";
    dest_dir = ({"players/kbl/corridor","south",
                 "players/kbl/big_forest1","west",
                 "players/kbl/towers/mid","east"});
    smell = "Cinnamon incense ... ahhh ... smells soooo gooood!";
    property = "no_steal","no_hide","no_fight";
    items = ({"plaque","It reads: You may find the way west both pleasent\n"+
                       "and dangerous. Look at everything. Think. Use your\n"+
                       "natural gifts and you shall do alright. The water\n"+
                       "and air have powers you may only dream of. Kbl's\n"+
                       "Parallel Plane of Chaos lies this direction, hope you can find it!",
              "portrait of elvin female","Protrait is titled \"Sunshine\" "+
                         "The portrait shows how deep her\n"+
                         "emotions run... deeper than any ocean\n",
                "sign","Maybe you should read it",
              "corner","Which corner?",
              "northeast corner","You see a decanter of incense",
              "chamber","You are in the chamber, Kbls' Entrance Chamber!",
              "northwest corner","You see the northwest corner!",
              "southwest corner","You see the southwest corner!",
              "southeast corner","You see the southeast corner!",
              "floor","Beautiful white marble with silver clover leaf\n"+
                      "designs inlaid into the marble. The floor is\n"+
                      "very clean",
              "walls","The walls are 15 meters high and near the ceiling\n"+
                      "they curve back in a gothic type design",
              "ceiling","This light blue ceiling makes you feel like you\n"+
                        "are looking out into the blue sky.",
              "floor","Beautiful multi colored marble very smooth",
              "portal","Blue shimmering portal. It feels very inviting",
              "dimension door","It glows with the power of a god. You may\n"+
                               "NOT want to enter it!",
              "stairway","The stairway goes up in the east wall. It looks\n"+
                         "very well used",
              "silver clovers","Patterns that are inlaid in the floor",
              "clovers","Silver clover patterns on floor make you feel alive!",
              "doors","The doors to the corridor are made of thick oak",
              "door","The doors to the corridor are made of thick oak"});
  }
}

init()
{
  ::init();
  add_action("north_b","north");
  add_action("get_it","get");
  add_action("get_it","take");
  add_action("north_b","n");
  add_action("enter_it","enter");
  add_action("look","l");
  add_action("look","exa");
  add_action("look","look");
  add_action("look","scan");
  add_action("press","push");
  add_action("press","press");
  add_action("search","search");
  add_action("read","read");
}

north_b()
{
    say(this_player()->query_name()+" stops going north for some reason.\n");
    write("A voice in your mind says: HOLD! You are not allowed.\n");
    write("You stop dead in your tracks as if commanded to by the voice.\n");
    return 1;
}

get_it(str)
{
  if(!str)
   return;
  switch(str)
  {
    case "paintings":
    case "painting":
         write("The paintings resist your every efforts to remove them.\n");
          return 1;
    case "decanter":
         write("Its firmly bolted to the wall.\n");
         return 1;
    case "table":
         write("Its a strudy and extremely heavy table. You cannot take it.\n");
         return 1;
  }
}

enter_it(str)
{
  if(!str)
   return;
  if(found_sec == 0)
  {
    write("Enter what??\n");
    return 1;
  }
  if(str == "secret door")
  {
    say(this_player()->query_name()+" enters secret door. It shuts tightly\n"+
        "behind "+this_player()->query_name()+".\n");
    write("You enter the secret door, going down into the dungeon!\n");
    this_player()->move_player("into secret door#players/kbl/dungeon/dun1");
    found_sec = 0;
    return 1;
  }
}

search(str)
{
  if(!str)
   return;
  if (str == "table" && this_player()->query_dex() > 11)
  {
   if (!found_panel)
   {
    say(this_player()->query_name() + " searchs the table.\n");
    write("You search across the middle of the table and find a panel by\n");
    write("sliding a cover to the left.  It reveals a simple push button\n");
    write("control with three buttons, one labeled food, one labeled drink\n");
    write("and the other smoke.  The stuff you get from here is not taken\n");
    write("with you.  AutoManagement\n");
    found_panel = 1;
    return 1;
   }
   else
   {
     say(this_player()->query_name()+" scans table.\n");
     write("You see a open panel in the middle of the table.\n");
     return 1;
   }
  }
  if(str == "floor")
  {
     say(this_player()->query_name()+" finds a secret door under the table.\n");
    write("You find a secret door under the middle of the table. You can see\n"+
          "the secret doors outline and its easily opened.\n");
    found_sec = 1;
    return 1;
  }
}

press(str)
{
  if(!str)
   return;
 if (str == "smoke")
 {
  if (num_s > 0)
  {
   if(tps != this_player())
   {
    say(this_player()->query_name() + " smokes a spliff down to ashes fast!\n");
    write("A rather large naturally rolled spliff jumps into your hand.\n");
    write("It lights itself and you feel your hand moving the spliff to\n");
    write("your mouth...  *puff* *puff* ahhhhhhhhhhh, nice.  *shiver*\n");
    write("You continue to smoke it down to ashes...  The smoke has filled\n");
    write("the air here...  All of a sudden, there's a rush of fresh air\n");
    write("and the room is cleared!   You look down at your hand, nothing\n");
    write("is there.   You feel much better tho, as if you been somewhere\n");
    write("else for a moment.\n");
    tps = this_player();
    this_player()->heal_self(15);
    num_s -=1;
    return 1;
   }
   else
   {
     write("Table thinks to you: You already had some smoke!\n");
     return 1;
   }
  }
  else
   write("You press button labeled SMOKE but nothing happens.\n");
 }
    if (str == "drink")
    {
     if (num_d > 0)
     {
      if(tpd != this_player())
      {
      say(this_player()->query_name() + " drinks a large mug of mead!\n");
       write("A large mug of sweet tasting mead appears in your hand.\n");
       write("You feel a powerful energy surround you as you lift the\n");
       write("mug to your lips.  Maybe you should think twice about\n");
       write("drinking another.  But it was so smooth and felt so good.\n");
       write("As you finish the mug it dematerializes leaving no trace of\n");
       write("its existance here.\n");
       tpd = this_player();
       this_player()->drink_alcohol(15);
       this_player()->heal_self(15);
       num_d -=1;
       return 1;
      }
      else
      {
        write("Table thinks to you: You already had a drink!\n");
        return 1;
      }
     }
     else
     {
       write("You press button labeled DRINK, but nothing happens.\n");
       return 1;
     }
    }
      if (str == "food")
      {
       if (num_f > 0)
       {
        if(tpf != this_player())
        {
         say(this_player()->query_name() + " eats a delightful meal!\n");
         write("A meal appears on the table infront of you.  Hmmmmm, smell\n");
         write("the roast beef and vegies!  A strawberry cake of such and\n");
         write("a decanter of water are also present. You eat and drink\n");
         write("until full.  A cloth appears and wipes your face for you\n");
         write("with such gental strokes it makes you feel alive! Ahhhh...\n");
         this_player()->eat_food(8);
         this_player()->heal_self(15);
        this_player()->drink_alcohol(-10);
        num_f-=1;
         tpf = this_player();
         return 1;
         }
         else
         {
           write("Table thinks to you: You already had something to eat!\n");
           return 1;
         }
        }
        else
          write("You press the button labeled FOOD, but nothing happens.\n");
      }
}

read(str)
{
   if(!str)
    return;
   if(str == "sign" || str == "at sign")
   {
     say(this_player()->query_name() + " looks at the floating sign.\n");
     write("Sign reads: This is room is made for your enjoyment and\n");
     write("fullfillment.  Please feel free to send mail to Kbl about\n");
     write("any ideas you may have to enchance anything you find in this\n");
     write("room or any other place contained within this castle.\n");
     return 1;
   }
}

look(str)
{
  if(!str)
   return;
     if(str == "table" || str == "at table")
     {
       say(this_player()->query_name() + " looks at the Large Oak table\n");
       write("A long retangular table is placed in the center of this long\n");
       write("retangular entrance hall.  No chairs here for some reason.\n");
       write("There is nothing on the top of the table, save the sign\n");
       write("floating directly above the table.  The table is made of\n");
       write("very thick oak.\n");
       return 1;
     }
      if(str == "decanter" || str == "at decanter")
       {
         say(this_player()->query_name() + " stares dreamily at the\n");
         say("decanter of incense in the northeast corner for a moment.\n");
         write("In the northeast corner you see the incense holder. It\n");
         write("continously sends a thin stream of smoke straight up into\n");
         write("the room. As you look the incense seems to waver and you\n");
         write("you feel a peace come over your body as you smell the\n");
         write("spice of the incense, ahhhhhh...\n");
         this_player()->heal_self(2);
         return 1;
       }
         if(str == "room" || str == "at room")
         {
           say(this_player()->query_name() + " scans the room.\n");
           long();
           return 1;
         }
           if(str == "panel" || str == "at panel")
           {
              if (found_panel)
              {
                 say(this_player()->query_name() + " looks at the panel on\n");
                 say("the Large Oak table.\n");
                write("You see a control panel in the center of the table.\n");
                write("There are three buttons on the panel labeled food,\n");
                write("drink and smoke.\n");
                return 1;
              }
              else
              {
                write("You don't seem to see any panel.\n");
                return 1;
              }
            }
              if(str == "paintings" || str == "at paintings")
              {
                say(this_player()->query_name() + " looks at the paintings\n");
                write("The paintings here are from artists of unknown\n");
                write("times and places.  Beautiful picture of trees in\n");
                write("great forests, mountains in the backround with a\n");
                write("stream running by you...  Another has the portrait\n");
                write("of a beautiful elvin female...  Another show black\n");
                write("creatures munching on the dead bodies of humans and\n");
                write("elvins alike. One picture is of a adventure wearing\n");
                write("a bright suit jumping into a beam of light in the\n");
                write("darkness.\n");
                return 1;
              }
}
