inherit"room/room";

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="",
    long_desc="";

    no_obvious_msg="";
    
  }
}

