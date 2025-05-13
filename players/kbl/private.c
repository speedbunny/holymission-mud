/* Kbl's private chambers V0.1 */

inherit "room/room";

int priv;
int doit;
int failures;
object tp;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(2);
    short_desc = "Kbl's private chambers";
    long_desc = "Deep purple velvet tapestries line all the walls depicting\n"+
                "violence begin overcome by love and understanding.\n"+
                "Frustration being overcome by inner strength and paranoia\n"+
               "being overcome by awareness.\n";
    smell = "Super fresh air, ALOT of oxygen here";
    dest_dir = ({"players/kbl/kblroom","south",
                 "players/kbl/workroom","work",
                });
    property = "no_hide","no_sneak","no_fire","no_fight","no_teleport";
    priv = 0;
    failures = 0;
  }
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("secure","lock");
  add_action("secure","unlock");
  if(this_player()->query_real_name() != "kbl" || priv == 1)
    do_kick();
}


look_it(str)
{
  if(!str)
   return;
  tp = this_player();
  switch(str)
  {
    case "at tapestries": say(capitalize(tp->query_real_name())+
              "looks all around at the beautiful purple velvet tapestries\n"+
              "lining all the walls.\n");
              write("You see the tapestries are finely made and and have\n"+
                    "many sceens depicting true love overcoming all odds.\n"+
                    "In the lower corner of the south wall tapestry, you see\n"+
                    "the words, \"Kbl loves Sunshine forever\".\n");
              doit = 1;
    case "at walls": say(capitalize(tp->query_real_name())+" looks around at"+
                         "the purple velvet walls.\n");
                     write("You see tapestries finely inlaid with sceens."+
                           " Maybe you should look at the tapestries, hmm?\n");
                     doit = 1;
                     break;
              break;
  }
  if(doit)
  {
    doit = 0;
    return 1;
  }
}

secure(str)
{
  string created;
  if(priv)
  if(query_verb() == "unlock" && priv == 1)
  {
    write("You unsecure the room.\n");
    priv = 0;
    return 1;
  }
  if(!str)
   notify_fail("No password no enter");
  tp = this_player();
  if(failures > 2)
  {
    created = creator(tp);
    if(!created)
     created = "System";
    log_file("kbl.illegal","This object named "+tp->query_name()+" created"+
                           " by "+created+", failed in attempts to enter\n"+
                           "the password for securing Kbl's private chambers.");
    failures = 0;
    return;
  }
  if(tp->query_real_name() != "kbl")
  {
    log_file("kbl.illegal","This player "+tp->query_real_name()+" tried to"+
                           "secure my private chambers. Date: "+ctime(time())+
                           " *****\n");
   failures++;
    notify_fail("You are not Kbl, you are being reported!");
  }
  switch(str)
  {
    case "sunshine": priv = 1;
                     write("You just secured this room!\n");
                     break;
    default: failures++;
             write("Wrong password, try again! *grin*\n");
             break;
  }
  return 1;
}

do_kick()
{
  write("You just tried to see me at a bad time... I'm sending you to\n"+
        "workroom, where you may either leave, or ring me!\n");
  transfer(tp,"/players/kbl/workroom");
}
