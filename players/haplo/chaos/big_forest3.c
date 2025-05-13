/* A beautiful forest with many trees and bushes */

inherit "room/room";
int berries;
object temp;

reset(arg)
{
 ::reset(arg);
 if(!arg)
 {
  set_light(1);
  short_desc = "On a narrow path in a wooded area";
  long_desc = "The bushes grow thick here. Birds chirp harmonously but\n"+
              "hidden in the high branches of the blue leaf trees that\n"+
              "that you can see growing all around. A great forest with\n"+
              "white crystal outcroppings covered in green moss scattered\n"+
              "about. The pathway goes north/south and the sounds of the\n"+
              "forest make you feel at ease here. Theres a small sign here\n"+
              "next to a rounded bush just off the path.\n";
  dest_dir = ({"players/kbl/expa/exp1","north",
               "players/kbl/big_forest2","south"});
  items = ({"sign","Sign reads: Bushes do not like double takers. The pines\n"+
                   "have birds that bite to death and the water in the pit\n"+
                   "might sweep you into a undesireable place",
            "moss","The moss seems to move slowly over the crystal.",
            "trees","80 meter tall maple trees",
            "portal","A shimmering blue portal that hangs suspended in the\n"+
                     "air in front of a large boulder of white crystal",
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
  berries = 5;
 }
 if(!present("leaf",this_object()))
 transfer(clone_object("players/kbl/objs/unfrog"),this_object());
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
    write("None of the branches are low enough to help climbing and the\n"+
          "trunks are very smooth making the trees unclimbable.\n");
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
