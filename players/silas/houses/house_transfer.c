
 /* house_transfer.c     Metaprat      6th April 1992  */

#include "/players/silas/houses/house_defines.h"


static string nullstring;

string main_room_desc;
string bedroom_room_desc;
string kitchen_room_desc;
string rooms_desc;
string rooms_short;
string furnishings;
int    rooms_x;
int    rooms_y;
string exits_special;
string exits_wizard;
int    exits_north;
int    exits_east;


restore_stats(str, receiveob) {
   log_file("metaprat.xfer",
      "Reading " + HOUSES_DIR + str + ", at " + ctime(time()) + ".\n");
   if (!restore_object(HOUSES_DIR + str)) {
      log_file("metaprat.xfer",
         "Restore_stats(" + str + ") failed - probably new house.\n" +
         "Will NOT use NEW_OWNER to restore, returning immediately.\n");
      return 0;
   }
   if (main_room_desc || kitchen_room_desc || bedroom_room_desc) {
      log_file("metaprat.xfer",
         "Transforming data file from Ver 1 to Ver 2 format.\n");
      if (main_room_desc) {
         rooms_desc[0]    = main_room_desc;
         rooms_short[0]   = "Main hallway";
         furnishings[0]   = "";
         rooms_x[0]       = 0;
         rooms_y[0]       = 0;
         exits_north[0]   = 0;
         exits_east[0]    = 0;
         exits_special[0] = ({"church"});
         exits_wizard[0]  = ({"workroom", "castle"});
         main_room_desc = nullstring;
      }
      if (kitchen_room_desc) {
         rooms_desc[1]    = kitchen_room_desc;
         rooms_short[1]   = "Kitchen";
         furnishings[1]   = "";
         rooms_x[1]       = 0;
         rooms_y[1]       = 1;
         exits_north[1]   = 1;    /* to/from main room */
         exits_east[1]    = 1;    /* to/from bedroom   */
         exits_special[1] = ({ });
         exits_wizard[1]  = ({ });
         kitchen_room_desc = nullstring;
      }
      if (bedroom_room_desc) {
         rooms_desc[2]    = bedroom_room_desc;
         rooms_short[2]   = "Bedroom";
         furnishings[2]   = "";
         rooms_x[2]       = 1;
         rooms_y[2]       = 1;
         exits_north[2]   = 0;
         exits_east[2]    = 0;
         exits_special[2] = ({ });
         exits_wizard[2]  = ({ });
         bedroom_room_desc = nullstring;
      }
   }
   receiveob->get_remote_house(rooms_desc,   rooms_short, furnishings,
                               rooms_x,      rooms_y,     exits_special,
                               exits_wizard, exits_north, exits_east);
   log_file("metaprat.xfer",
            "House transferred to /players/pakka/houses/" + str + ".o\n");
   log_file("metaprat.xfer",
            "Destination house was " + file_name(receiveob) + ".\n");
   return 1;
}






