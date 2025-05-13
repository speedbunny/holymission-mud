inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Kbl's Cloud";
    long_desc = "Kbls cloud above Cloud City. Its impossible to see\n"+
                "anything here except blue sky.\n";
    dest_dir = ({
                 "/room/church","church",
                });
    items = ({
              "blue sky"," You see Pink Floyd in the sky",
              "sky"," You see Pink Floyd in the sky",
              "pink floyd","A shimmering image of a future age",
              "cloud","You are standing on it",
             });
  }
}
