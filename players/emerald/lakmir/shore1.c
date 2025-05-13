inherit "room/room";

void reset(int arg) {

  if (arg) return;

  set_light(1);


  short_desc="On the shore";
  long_desc="The long, slow waves roll in gently from the shallow bay to " +
            "the east.  Seabirds dart in and out of the water, catching " +
            "fish.  To the west lies the land of the Druid Lakmir.  The " +
            "bay is shallow enough at this point to wade in.\n";

  smell="The air smells salty here";

  dest_dir=({"/players/emerald/lakmir/shore2","north",
             "/players/emerald/lakmir/ocean1","east",
             "/players/emerald/lakmir/southgate","west"
           });

  items=({"waves","Small aquamarine waves rolling on to the shore",
          "bay","A good place to catch some fish",
          "water","The main component of the ocean",
          "fish","They make a tasty soup",
          "seabirds","Gulls and another voracious avain creatures",
          "land","Terra firma",
        });


  ::reset();
  replace_program("/room/room");

}
