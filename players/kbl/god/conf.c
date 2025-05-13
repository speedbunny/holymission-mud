inherit "/players/kbl/objs/gcity";
#define TPRN this_player()->query_real_name()
#define TPQL this_player()->query_level()
#define TP   this_player()
#define CTPRN capitalize(TP->query_real_name())

string valids;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
   valids = ({
               "kbl",
               "windmaster",
               "dancer",
               "muzmuz","mangla","horatio",
               "silas",
               "meecham","warlord","uglymouth","galadriel","airborne","herp",
               "stormwind","matt","colossus","cashimor","james","sourcer",
               "tristan",
              });
    set_city_name("none","Crystal City");
    long_desc = "This is a basic private conference room. Buildings all\n"+
                "around are tall and sealed.\n";
  }
}

init()
{
  if(member_array(TP->query_real_name(),valids) == -1)
  {
    write("Bye... see ya later...\n");
    TP->move_player("quickly#room/church");
    return;
  }
 write("Welcome "+CTPRN+" to Kbl's private haven\n");
  ::init();
  add_action("outer","o");
}

query_matrix()
{
  return "/players/kbl/cpower/core";
}

outer()
{
  TP->move_player("home#/players/"+TPRN+"/workroom");
  return 1;
}
