#define TP this_player()
inherit "/room/room";

void reset(int arg) {
 if(arg)return;

 set_light(1);
 short_desc="On an island";

 long_desc="Bushes line the southeastern edge of this plateau.  The "+
           "other sides drop off, allowing a view of the clear blue sea.  "+
           "You can also sea the lovely beach below you.  The water is "+
           "probably deep enough for you to risk a jump down to the beach.\n";

 items=({"bushes","They are only about four feet high, and could be passed",
         "sea","The clear blue sea",
         "beach","A long sandy beach",
         "edge","There are bushes along the southeastern edge",
         "plateau","A plateau near the top of the volcano",
         "sides","Most sides of the plateau are a sheer drop to the sea",
         "water","It seems very deep",
         "view","A wonderful view of the sea",
       });


  clone_list=({
    1,1,"armonophis","/players/emerald/island/obj/armonophis",0,
    -1,1,"skin","obj/armour",({
      "set_name","dragonskin",
      "set_alias","skin",
      "set_type","armour",
      "set_ac",4,
      "set_size",4,
      "set_short","A heavy Dragonskin",
      "set_long","The excellent armour of Armonophis the confused Dragon.\n",
      "set_value",8000,
      "set_weight",3,
    }),
    -1,1,"sword","/players/emerald/island/obj/h_sword",0,
    2,1,"tree","/players/emerald/island/obj/tree2",0,
  });

  ::reset(arg);

}
void init() {
  ::init();
  add_action("_jump","jump");
  add_action("_pass","pass");
}
_jump(string str) {
 if(!str) {
    notify_fail("Jump where?\n");
    return 0;
  }
  if(str=="down") {
    write("\n\n\n*********** y o u  a r e  f a l l i n g ***********\n\n\n"+
                "*********** y o u  a r e  f a l l i n g ***********\n\n\n"+
                "*********** y o u  a r e  f a l l i n g ***********\n\n\n"+
                "*********** y o u  a r e  f a l l i n g ***********\n");
  TP->move_player("down#players/emerald/island/room/i26");
  return 1;
  }
}
_pass(arg) {
  if(arg!="bushes") {
    notify_fail("Pass what?\n");
    return 0;
  }
   if(arg=="bushes") {
     write("You pass the big bushes.\n");
     TP->move_player("over the bushes#players/emerald/island/room/i22");
     return 1;
   }
}
