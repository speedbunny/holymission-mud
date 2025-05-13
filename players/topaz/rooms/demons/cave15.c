inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
object queen, lady1, lady2;
  ::reset(arg);
  if(!arg) {

     short_desc = "The Demon Queen's Chambers";
    long_desc = "You have entered the Demon Queen's chambers.\n" +
                 "Everything here is nice!  Her bed is covered with silk.\n" +
                 "There is a small table with an assortment of perfumes on\n" +
                 "it and on a larger table sit some cosmetic items.\n";

      dest_dir = ({"players/topaz/rooms/demons/cave14","down",
 
                     });

     items =({"chamber","The Demon Queen spends all her time here",
              "chambers","The Demon Queen spends all her time here",
              "perfume","Many different scents which smell surprisingly good",
              "perfumes","Many different scents which smell surprisingly good",
              "assortment","There are many different colored bottles of " +
                           "perfume",
              "bottle","A bottle of expensive perfume",
              "bottles","Many bottles of expensive perfume",
              "table","Which one?  There is a small table and a large table",
              "small table","A small nightstand that the Queen keeps her " +
                            "perfumes on",
              "large table","There are many cosmetic items on it",
              "items","Oh, blush, lipstick.  That sort of thing",
              "cosmetic items","Oh, blush, lipstick.  That sort of thing",
              "cosmetics","Oh, blush, lipstick.  That sort of thing",
              "bed","It is beautiful!  It is covered with silk",
              "silk","It looks expensive",
              });
       set_light (1);
       smell = "You smell the strong scent of many perfumes.";
       move_object(queen=clone_object(MDEMONS + "queen"),this_object());
       move_object(lady1=clone_object(MDEMONS + "lady"),this_object());
       move_object(lady2=clone_object(MDEMONS + "lady"),this_object());
  }
  return 1;
}
