inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

   short_desc = "beach";
     long_desc = "You are standing on the beach just south of the anchoring place.  This is a\n"+
	"most beautiful beach.  It appears untouched by human interference.\n"+
  "The sound of the ocean tide crashing against the shore gives no indication\n"+
	"of anything living here.\n";

       
      items =({"anchoring place","An anchoring place with a landing stage",
               "ocean","The blue ocean"});

      dest_dir = ({"players/muzmuz/island/rooms/di","north",
                    });
      set_light (1); 
      }
}
