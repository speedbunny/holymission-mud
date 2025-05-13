
inherit "room/room";

query_no_teleport() { return 1;}

reset(arg) {

if (arg) return;

   set_light(1);
   no_castle_flag = 1;
   property ="no_teleport";
   short_desc = "MYSTERY ZONE";
   long_desc =
     "You are standing in the MYSTERY ZONE.\n"+
     "In here all your nightmares and dreams might come true.\n"+
     "In here anything is possible.\n";


   items =({
          "nightmares","Terrible dreams in the middle of the night,\n"+
                       "what else did you expect a nightmare to be ??\n",
          "nightmare","A terrible dream in the middle of the night,\n"+
                      "what else did you expect a nightmare to be ??\n",
          "dreams","Nice dreams",
          "dream","A nice dream",
          "anything","Could be all, and could be nothing",
          "all","Everything",
          "nothing","You look but there is nothing there",
          "ZONE","The mystery zone",
          "zone","The mystery zone",
          "Mystery zone","It's a hole in the fabric of space and time",
          "MYSTERY ZONE","A hole in the fabric of space and time"
          });


   smell = "The smell of fear and pleasure mixed very well";
}
