inherit "room/room";
int move(string str) {
  object ob;
  if(!str)
    str = query_verb();
  if((str == "north" || str == "south") && (ob=present("gamorrean guard", this_object())) &&
      !this_player()->query_immortal() && this_player()->query_invis() <
      ob->query_level() + 10) {
    write("The guard laughs at your attempt to pass him!\n");
    ob->attack_object(this_player());
    return 1;
  }
  return ::move(str);
}

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "The main greeting hall of Jabba's Palace.";     
        long_desc = "\
You have entered the main greeting hall at Jabba's palace.  The walls around you \
are decorated with tapestries, and the floor is carpeted in rich blue, unspoiled \
by the many people who have passed through this place.  It is surprisingly well \
kept, considering the monsterous fiend who lives here, and you imagine he keeps \
his workers on a tight leash. You see a long hallway stretching off into \
the distance, carpeted in royal blue.\n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/14",  "south",
            "/players/redsexy/jedi/areas/desert/d51", "north",

        });

        clone_list = ({

           1, 1,"guard","players/redsexy/jedi/monsters/guard",0,
         });


         items = ({
             "hall", "The main greeting hall of Jabba's palace",            
             "walls", "They seem to be made of marble, but the tapestries \
cover the full legnth so it is hard to tell",
             "tapestries", "Richly embrodiered tapestries, mainly various coats \
of arms from across the realms",       
             "floor", "The floor is carpeted in rich blue, and the carpet continues \
to the south",
             "carpet", "This carpet is a very royal blue, and unspoilt",
             "fiend", "The palace belongs to Jabba the Hutt",
             "hallway", "Two very long hallway lies ahead, and the desert is just outside",
       });
    }
    ::reset(arg);
    replace_program("room/room");
}


