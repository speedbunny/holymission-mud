inherit "room/room";

void reset (int arg) 
{
  if (!arg) 
  {
       short_desc = "east coast";
       long_desc = "You are standing at the coast. This place is exposed and so a breeze is\n" +
                    "blowing through your hair. You can see a little bay from here. The ocean is\n" +
                    "very silent. It seems to be lifeless.\n";

         dest_dir =({"players/muzmuz/island/rooms/ki","north",
                     "players/muzmuz/island/rooms/jj","west",
                             });

        items = ({"bay","A romantic little bay",
                  "ocean","The blue ocean",
                         });
        set_light (1);
        }
}
