/* A beautiful forest with many trees and bushes */

inherit "room/room";
int berries;
object plate_mail;
object temp;

reset(arg)
{
 ::reset(arg);
 if(!arg)
 {
  set_light(1);
  short_desc = "On a narrow path in a wooded area";
  long_desc = "The bushes grow thick here. Birds chirp harmoniously but\m"+
              "hidden in the high branches of the blue leaf trees that\n"+
              "that you can see growing all around. A great forest with\n"+
              "white crystal outcroppings covered in green moss scattered\n"+
              "about. A shimmering blue portal leads back to Kbl's castle.\n"+
              "The sounds of a distant waterfall greets your ears. Theres\n"+
              "a small sign here next to a rounded bush just off of the path\n";
  dest_dir = ({"players/kbl/falls1","north",
               "players/kbl/kblroom","portal"});
  items = ({"sign","Sign reads: Beware, the water bites at One Falls. You\n"+
                   "may never surface again! The bush don't like double\n"+
                   "takers! Look at everything, you may miss something.",
            "moss","The moss seems to move slowly over the crystal.",
            "portal","A shimmering blue portal that hangs suspended in the\n"+
                     "air in front of a large boulder of white crystal",
            "trees","80 meter tall maple trees",
            "bushes","The bushes are scattered all over but one rounded\n"+
                     "bush near the edge of the path catches your eye",
            "forest","The forest is thick in all directions with maple\n"+
                     "type trees. There blue leaves create a beautiful\n"+
                     "array of colors as the suns light filters through\n"+
                     "them. The forest seems to thin out looking west.",
            "branches","Looking up at the high branches you see birds\n"+
                       "fluttering about. They are so high up that you\n"+
                       "cannot see them clearly. The branches look green\n"+
                       "in the blue light."});
  smell = "The air is very fresh, seems to give you a lift";
  if(!plate_mail)
  {
    plate_mail = clone_object("obj/armour");
    plate_mail->set_name("A suit of platemail");
    plate_mail->set_alias("platemail");
    plate_mail->set_short("platemail");
    plate_mail->set_long("A nice piece of armour\n");
    plate_mail->set_value(500);
    plate_mail->set_weight(2);
    plate_mail->set_ac(1);
    plate_mail->set_type("armour");
    transfer(plate_mail,this_object());
  }
  berries = 5;
 }
}


init()
{
  ::init();
  if(berries == 0)
   berries = random(6)+1;
  add_action("get_it","get");
  add_action("climb","climb");
  add_action("look_it","look");
  add_action("look_it","scan");
}


climb(str)
{
  if(!str)
   return;
  if(str == "tree" || str == "maple tree" || str == "trees" || str == "maple trees")
  {
    write("None of the trees have branches low enough to help climb. The\n"+
          "trunks of the trees are rather smooth.\n");
    say(this_player()->query_name()+" tries to find a climbable tree but fails.\n");
    return 1;
  }
}

get_it(str)
{
  if(!str)
   return;
  if(str == "berry" || str == "berry from bush")
  {
    if(temp != this_player())
    {
      if(berries > 0)
      {
        write("Berry looks SO delicious, you eat it!\n");
        say(this_player()->query_name()+" picks a berry and eats it.\n");
        this_player()->heal_self(5);
        temp = this_player();
        berries-=1;
        return 1;
      }
      else
      {
        write("Bush says: HEY, the berries are all gone!\n");
        say("Bush says: HEY, the berries are all gone!\n");
        return 1;
      }
    }
    else
    {
      write("Bush says: You JUST had some!\n");
      say("Bush pulls away from "+this_player()->query_name()+"'s reach!\n");
      return 1;
    }
  }
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at bush" || str == "bush")
  {
    write("Bush is about 4' tall and rounded like someone keeps it that\n");
    write("way. Its leaves shine from internal light. The smell here is\n");
    write("sweetness above the normal. The bushes around have berries on\n");
    write("them.\n");
    if(berries == 1)
      write("You see one pickable berry on the bush.\n");
    if(berries > 1)
      write("There might be a berry or two, you see "+berries+" berries.\n");
      return 1;
  }
  if(str == "at crystal" || str == "crystal")
  {
    write("The crystal around here looks very weather beaten and as you\n");
    write("look at the crystal, it crumbles a little.\n");
    return 1;
  }
  if(str == "at berry" || str == "berry")
  {
    if(berries > 0)
     write("The berry looks like a big purple grape. It smells so good!\n");
    else
     write("No berries to look at.\n");
    return 1;
  }
}
