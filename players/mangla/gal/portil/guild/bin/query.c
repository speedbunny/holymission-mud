query(string str) {
        int timer;
        string ticktime;

        if(str!="time") { notify_fail("What do you wish to query?\n");
                          return 0;
        }
        timer="/obj/tick"->qry_timer_value();

	if(timer==-1) write("You look towards the sky to check the sun but a sheet of clouds is casting a veil over the dark sky and you know that the end has come.\n");
         else {
              if(timer>5400) ticktime="is about "+(timer+1800)/3600+" hours";
              else if(timer>3600) ticktime="is over 1 hour";
              else {   timer%=3600; timer/=60; 
                if(timer>1) ticktime="is just over "+timer+" minutes";
                else ticktime="is about 1 minute";
              } 
              write("You look up towards the sky and from the position of the sun you can tell there "+ticktime+" left until the world dies.\n");
        }
        say(capitalize(this_player()->query_name())+" looks towards the sky and checks the position of the sun.\n");
        return 1;
}
