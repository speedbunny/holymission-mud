inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Dead end";
    long_desc = "Dead end in this mundane cave\n";
    dest_dir = ({
                 "/players/kbl/expa/exp4","southeast",
                });
    items = ({
              "cave","Your in it",
              "dead end","Its ends here",
              "end","Its dead ends here",
             });
    property = "no_fire","no_hide";
    smell = "Cool and dry with a hint of a musty odor";
  }
}

init()
{
  ::init();
}
