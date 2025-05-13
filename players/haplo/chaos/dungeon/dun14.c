inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Crawl space";
    long_desc = "Crawl space thats been well used. There's alot of moss\n"+
                "growing on the smooth walls.\n";
    dest_dir = ({
                 "/players/kbl/dungeon/dun20","crawl",
                 "/players/kbl/dungeon/dun15","west",
                });
    items = ({
              "moss","Green moss, you wonder how it got its color",
              "crawl space","Your in it",
              "walls","Smooth walls with moss growing on them",
             });
  }
}

init()
{
  ::init();
}
