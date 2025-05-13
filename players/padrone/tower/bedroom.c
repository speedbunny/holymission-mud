
/* bedroom */

inherit "/room/room";

void reset(int flag)
{
     if (flag == 0)
     {
       set_light(1);
       short_desc = "In an erotique bedroom";
       long_desc =
       "You are now in the Wizard's bedroom.\n" +
       "The light is soft, the carpets are thick, the furniture is\n" +
       "luxurious and in the middle of the room there is a huge waterbed\n" +
       "with down pillows. You are lucky, because it seems like the Wizard\n" +
       "is not here. If he had been, he would surely have transformed you\n" +
       "into a newt for this unprecedented intrusion. To the east a door\n" +
       "leads into a wardrobe.\n"; 
       dest_dir = ({
           "players/padrone/tower/hall", "north",
	   "players/padrone/tower/wardrobe", "east",
	   "players/padrone/tower/poolroom", "northwest",
       });
       items = ({
       "bed",
	"It looks very comfortable, but don't bother searching in it.\n"+ 
        "There are no rings of healing in this bed.\n"+ 
        "Try Kitiara's bed, in Kantele mansion, instead...",
       "waterbed",
	"It looks very comfortable, but don't bother searching in it.\n"+ 
        "There are no rings of healing in this bed.\n"+ 
        "Try Kitiara's bed, in Kantele mansion, instead...",
       });
      }
}
   

