inherit "room/room";

reset(arg)
{
   if (!arg)
{
  set_light(1);
    short_desc = "A testroom";
   long_desc = "This is the testroom of Szabolcs.\n";
dest_dir = ({                  });
}
}
init()
{
  ::init();
}
