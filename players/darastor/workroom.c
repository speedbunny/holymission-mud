/* Do any name definitions here */
inherit "room/room";
#include "/players/darastor/include/defs.h"
int locked;

int _send(string str)
{
    object who, card;
    string who_name;
    
    if(!str)
        return 0;

    if(sscanf(str,"card to %s",who_name))
    {
        if(who=find_player(who_name))
        {
            tell_object(TP,"You send a card to " + who->query_real_name(1) +
              ". How nice.\n");
            tell_object(who,TP->query_real_name(1) + " sends you a card.\n");
            card = clone_object("/players/sauron/clone/XmasCard");
            move_object(card,who);
            return 1;
        }
        else
        {
            notify_fail("Send what to whom?\n");
            return 0;
        }
    }
    else
    {
        notify_fail("Send what to whom?\n");
        return 0;
    }
}

int _rtattoo(string str)
{
    object who;
    string who_name;
    string tattoo_string;
    
    if(parse_command(str,this_object(),"%w %s",who_name,tattoo_string))
    {
        if(who=find_player(who_name))
        {
            tell_object(this_player(),"You tattoo \"" + tattoo_string +
              "\" across "+ capitalize(who->query_real_name()) + "'s " +
              "backside.\n");
            tell_object(who,capitalize(this_player()->query_real_name()) +
              " tattoos \"" + tattoo_string + "\" across your backside, from " +
              "a distance.\n");
            return 1;
        }
        notify_fail("No such living logged in.\n");
        return 0;
    }
    notify_fail("rtattoo <who> <message>");
    return 0;
}

int _rstroke(string str) {
    object who;
    if(who=find_player(str)) {
        tell_object(this_player(),"You affectionately stroke "
          + capitalize(who->query_real_name()) +".\n");
        tell_object(who,capitalize(this_player()->query_real_name())+" strokes"
          + " you affectionately from afar.\n");
        return 1;
    }
    notify_fail("No such living logged in.\n");
    return 0;
}

int _rgrope(string str) {
    object who;
    if(who=find_player(str)) {
        tell_object(this_player(),"You grope "
          + capitalize(who->query_real_name()) + " enthusiastically.\n");
        tell_object(who,capitalize(this_player()->query_real_name())+" gropes"
          + " you enthusiastically from afar.\n");
        return 1;
    }
    notify_fail("No such living logged in.\n");
    return 0;
}

int _rpinch(string str) {
    object who;
    if(who=find_player(str)) {
        tell_object(this_player(),"You pinch "
          + capitalize(who->query_real_name())+" on the behind.\n");
        tell_object(who,capitalize(this_player()->query_real_name())+" pinches"
          + " you right on the backside.\n");
        return 1;
    }
    notify_fail("No such living logged in.\n");
    return 0;

}
int _rbite(string str) {
    object who;
    if(who=find_living(str)) {
        tell_object(this_player(),"You bite "
          + capitalize(who->query_real_name()) +" in the behind!\n");
        tell_object(who,capitalize(this_player()->query_real_name())
          + " bites your backside!\n");
        return 1;
    }
    notify_fail("No such living logged in.\n");
    return 0;
}

int _rslurp(string str) {
    object who;
    if(who=find_living(str)) {
        tell_object(this_player(),"You slurp revoltingly at "
          + capitalize(who->query_real_name())+".\n");
        tell_object(who,capitalize(this_player()->query_real_name())

          + " slurps revoltingly at you from afar.\n");
        return 1;
    }
    notify_fail("No such living logged in.\n");
    return 0;
}

int _rmoon(string str) {
    object who;
    if(who=find_living(str)) {
        tell_object(this_player(),"You moon drunkenly at "
          + capitalize(who->query_real_name())+".\n");
        tell_object(who,capitalize(this_player()->query_real_name())
          + " drunkenly moons at you! How gross!\n");
        return 1;
    }
    notify_fail("No such living logged in.\n");
    return 0;
}

int _listen() {

  tell_object(this_player(),"The music sounds strange at first. As you listen" 
        +                  " to it it takes shape. Darastor is in fact playing"
        +                   " three vastly different CDs simultaneously, one"
+                           " through each\n" + "set of speakers.\n");
  return 1;
}


int _lock(string str) {
  if((!str)||(str!="workroom")) {
    notify_fail("Lock what?\n");
    return 0;
  }
  if(TP->query_real_name()!="darastor") {
    tell_object(TP,"You don't have the right to lock Darastor's workroom.\n");
    return 1;
  }
  tell_object(TP,"YOU LOCK YOUR WORKROOM.\n");
  locked = 1;
  return 1;
}
int _unlock(string str) {
  if((!str)||(str!="workroom")) {
    notify_fail("Unlock what?\n");
    return 0;
  }
  if(TP->query_real_name()!="darastor") {
    tell_object(TP,"You don't have the right to unlock Darastor's workroom."
      + "\n");
    return 1;
  }
  tell_object(TP,"YOU UNLOCK YOUR WORKROOM.\n");
  locked = 0;
  return 1;
}
/* This procedure is called every hour at the moment. The first
time it is called with the arg = 0, after that arg is always 1 */

reset(arg) {
    if (!arg) {
    /* first we need to decide on light level */
    set_light (1);
    /* then the brief description */
    short_desc = CNAME + "'s workroom.";
    /* now the long standard room description */
    long_desc = "This is the workroom of " + CNAME + "." +                   
                " This room is a MESS. You wonder how he can possibly do any" 
+               " useful work in"
 +              " this tip. The floor is invisible under a thick layer of" 
+               " junk, much of which"
+               " looks pretty unsavoury. The air here has a characteristic " 
           +    "smell and the"
+               " racket blaring through the room from the stereo defies "
+               "belief."
+               "There is a desk in the corner but you"
+               " doubt whether you can actually reach it "
+               "bearing in mind the state"
+               " of the floor. In the middle of the room there is a large"
+               " computer terminal - a 'Better Than Life' game where Rimmer's"
+               " warped psyche can wreak its evil revenge on him for being"
+               " such a total smeghead.\n";

    dest_dir=({
             "room/post","post",
             "room/church","church",
             "room/adv_guild","guild",
             "/players/darastor/beach_area/rooms/clifftop","seaside",
    });

   /* item descriptions here */
    items=({
         "junk","A pile of trash consisting largely of cigarette ends,"
+               " beer cans, half-eaten pizza slices and kebab papers",
       "stereo","The stereo dominates one wall of the room. You can count"
+               " three pairs of speakers",
         "desk","You can't get close enough to examine the desk in detail",
    });

   /* Properties of room here */
    property = ({
              "no_teleport","no_sneak","no_steal",
    });

   /* set smell here */
    smell = "This room reeks of bad pizza, even worse kebabs, cheap beer"
    +       " and stale cigarette smoke.";
  }
  }
init()
{
  object darastor;
  if(TP->query_real_name()=="darastor") {
    tell_object(TP,"YOU UNLOCK YOUR WORKROOM!\n");
  }
  else if(!present("darastor",TO) && !TP->query_archwiz()) {
    tell_object(TP,"You cannot enter Darastor's workroom while he is out!\n");
    TP->move_player("to the church","/room/church");
    return;
  }
  if(locked) {
    tell_object(TP,"You cannot enter Darastor's workroom - he has locked it."
      + "\n");
    TP->move_player("to the church","/room/church");
    return;
  }
  ::init();
  add_action("_send","send");
  add_action("_rstroke","rstroke");
  add_action("_lock","lock");
  add_action("_unlock","unlock");
  add_action("_listen","listen");
  add_action("_rslurp","rslurp");
  add_action("_rmoon","rmoon");
  add_action("_rbite","rbite");
  add_action("_rgrope","rgrope");
  add_action("_rpinch","rpinch");
  add_action("_rtattoo","rtattoo");
}
