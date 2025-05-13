inherit"room/room";

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="The Port of Holy Mission";
    long_desc="This is the great seaport of Holy Mission. You see the open\n" +
              "sea to the west.  The sea is particulary rough today and \n"+
              "only the brave or the foolish should make the journey to one \n"+
              "of the islands. Some fisherman are repairing their nets, and \n"+
              "many people sit around the piers drinking ale.  Some of them \n"+
              "are sailors, some dock workers, and a few are Captains.  \n"+
               "Next to you is a very old sailor who is selling tickets for \n"+
               "sea voyages.  Perhaps you could buy one.\n";
    
    items=({"pier","This is pier number 666",
            "sailor","He looks really old",
            "sea","It's very rough"});

    property =({"no_sneak","no_steal","no_hide"});

    dest_dir =({"/room/jetty2","west",
                "/room/sea","east"
              });

    smell = "You smell the fresh air";

   move_object(clone_object("/players/beardy/obj/checker"),"/players/capablanca/guild/restroom");
   move_object(clone_object("/players/beardy/obj/checker"),"/players/capablanca/guild/restroom");
   move_object(clone_object("/players/beardy/obj/checker"),"/players/capablanca/guild/fighter/entr3");
   move_object(clone_object("/players/beardy/obj/checker"),"/players/capablanca/guild/fighter/entr3");
   move_object(clone_object("/players/beardy/east_harbour/obj/sign"),this_object());

    move_object(clone_object("/players/beardy/east_harbour/monster/sailor"),this_object());
  }
}

