inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {
 
     short_desc ="hill";
      long_desc ="You are standing on a little hill. You see the beach and the anchoring place\n" +
                 "to the north and the bay to the northwest. The south is leading to the swamps.\n";

     items =({"beach","A nice beach with an anchoring place",
              "anchoring place","An anchoring place with a landing stage",
              "bay","A nice romantic bay",
              "swamps","Huge swamps with mosquitos"});
       dest_dir =({
                   "players/muzmuz/island/rooms/dl","south",
                   "players/muzmuz/island/rooms/ck","west",
                      });
      set_light (1); 
      }
}
