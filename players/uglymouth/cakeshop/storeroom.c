/* A room to temporarily store the cakes */
inherit "room/room";

reset(arg) {
   if(arg) return;

   set_light(1);
   short_desc = "The storeroom of the confectioner's shop";
   long_desc  = "This is the storeroom of the confectioner's shop. \n"
      + "Cakes that are ready and paid for are temporarily stored \n"
      + "here until called for, so nothing happens to them. \n";
   dest_dir = ({
      "/players/uglymouth/cakeshop/cakeshop","south",
      });
   items = ({
      "storeroom","A clean room to store cakes", 
      "room","A clean room to store cakes",
      });

   replace_program("room/room");
   }

