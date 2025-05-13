inherit "room/room";
#define TOH(x) transfer(x,this_object())
#define CDCRY clone_object("/players/kbl/cpower/decrystal");
object decry;

reset(arg)
{
  if(!arg)
  {
    set_light(1);
     short_desc = "A decrystal room";
    long_desc = "Swirling gray and white mist make up the walls of this\n"+
                "area. There's a bright red ball floating here.\n";
    dest_dir = ({
                 "/players/kbl/hall/hall1","hall",
                });
    decry = CDCRY;
    decry->set_place("The church");
    decry->set_trans_to("/room/church");
    decry->set_descrip("Bright blue ball");
    decry->set_color("blue");
    TOH(decry);
    items = ({
              "ball","Decry ball",
              "red ball","Decry ball",
              "walls","Gray and white with no definite shapes",
              "wall","Gray and white with no definite shape",
             });
  }
}

init()
{
  add_action("touch","touch");
   add_action("scan","scan");
}

scan()
{
  write("You cannot scan here. Try read decry instead!\n");
  return 1;
}

touch(str)
{
  if(!str)
  {
    write("Touch what?\n");
    return 1;
  }
  switch(str)
  {
    case "ball":
        write("It moves away from you.\n");
        return 1;
    case "walls":
        write("They feel cold and you start to feel lonely. Strange, huh?\n");
        return 1;
    default:
        write("Touch "+str+"?\n");
        return 1;
  }
}

query_name()
{
  return short_desc;
}

query_access()
{
  return 10;
}

query_cry_type()
{
  return "Axtiom";
}
