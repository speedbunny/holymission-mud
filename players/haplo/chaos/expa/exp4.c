inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Rough looking cave";
    long_desc = "Not much of a cave. Smooth walls and dirty floor\n";
    dest_dir = ({
                 "players/kbl/expa/exp3","south",
                 "players/kbl/expa/exp5","north",
                 "players/kbl/expa/exp6","northwest",
                });
    items = ({
              "cave","You are in it",
              "floor","Dirty and has many tracks mostly going north",
              "walls","Smooth from years of ancient rains",
              "tracks","HUGE claw marks in the dirty floor",
             });
    property = "no_hide";
    smell = "Nasty musty odor";
  }
}

init()
{
  ::init();
  add_action("trap","search");
}

trap(str)
{
  if(!str)
   return 0;
  if(str == "things")
  {
   transfer(clone_object("/players/kbl/objs/s"),this_player());
   return 1;
  }
}
