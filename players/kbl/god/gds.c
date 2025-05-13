inherit "/players/kbl/objs/thing";

#define CP(x) capitalize(x)
#define QRN query_real_name()
#define QL query_level()
#define GM "/guild/master"
#define E(x) environment(x)
#define QG   query_guild()
#define TPRN this_player()->query_real_name()

int guilds;
string *users;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(10);
    name = "displayer";
    short_desc = "Guild displayer";
    long_desc = "Custom display of guild members present. Commands:\n"+
                "     **** Guild display device ****\n\n"+
                "  say display guild <number> - Shows memberlist and locale\n"+
                "  say display guild all      - Shows memberlist and locale\n"+
                "                               of all the current guilds\n"+
                "              *** EOD ***\n";
    weight = 0;
    value = 0;
    read_message = "A wand of Guild Display";
    guilds = "/guild/master"->query_nog();
    users = ({
              "kbl","galadriel","uglymouth","warlord","airborne",
             });
  }
}

init()
{
  ::init();
  add_action("display","say");
}

display(str)
{
  string in2;
  int    in1;
  int    com;

  if(!str)
   return;
  if(member_array(TPRN,users) != -1)
    if(sscanf(str,"display guild %s",in2) == 1)
    {
      if(in2 != "all")
      {
        sscanf(str,"display guild %d",in1);
        com = filter(in1);
      }
      else
        com = filter(in2);
    }
  if(com)
   return 1;
  return 0;
}

filter(str)
{
  int    i;
  object *u;
  object *g;

  u = users();
  if(str != "all")
  {
    g = ({});
    for(i=0;i<sizeof(u);i++)
     if(GM->query_name(u[i]->QG) == GM->query_name(str))
       g += ({ u[i] });
    spresent(g);
    return 1;
  }
  if(str == "all")
  {
    spresent(u);
    return 1;
  }
  return 0;
}

spresent(object *obj)
{
  int i;

  write("Total of "+sizeof(obj)+" selected per display choice.\n\n");
  write("        Player names  Guild#                            Current Location\n");
  write("------------------------------------------------------------------------\n");
  for(i=0;i<sizeof(obj);i++)
   printf("%20s\t%4d\t%40s\n",CP(obj[i]->QRN),obj[i]->QG,
                                  file_name(E(obj[i])));
}
