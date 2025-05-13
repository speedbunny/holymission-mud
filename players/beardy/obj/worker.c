inherit "obj/thing";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("slave");

    set_short("directory slave");
    set_long("Say to and the dir\n");

  }
}

init()
{ add_action("to","to");
  ::init();
}

to(str)
{ switch(str)
  { case ".p"       : command("cd/player",this_player()); break;
    case ".p.b"     : command("alias slave cd /players/beardy",this_player());
                      command("slave",this_player());
                      break;
    case ".p.w"     : command("/sys/cd /player/whisky",this_player()); break;
    default : write("No such dir saved.\n");
  }
  return 1;
}
