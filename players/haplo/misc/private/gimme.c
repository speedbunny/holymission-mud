inherit "room/room";
#include "/players/haplo/def.h"
#include "/players/haplo/break_string.h"

  object ob;
reset(arg)
{
    if(arg) return;

    set_light(1);
    short_desc="Cave of the Serpent";
    long_desc= break_string(
     "This is a room where the mighty Shogun Haplo allows people to replace"+
     "items that were lost or are needed. This rooms will only allow you to"+
    "replace that which Haplo feels you are allowed to have."+
    "To get your iten type  gimme (item).\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
      "floor","The floor is rough and covered with little holes",
      "holes","The holes are very shallow and only appear to threaten unwary ankles"});

   dest_dir=({ "players/haplo/workroom", "out",});
property=({"no_teleport","no_sneak"});
}
   void init(){
   ::init();
   AA("_gimme","gimme");
 }

 _gimme(str){
     if(!str){
     write("Shogun Haplo will not allow you to have that!\n");
     return 1;
  }

    else {
   if(str=="star"){
   ob=clone_object("/players/haplo/ishikawa/obj/star");
   move_object(ob,this_player());
   write("Your request is granted!\n");
  say("It has been given!\n");
    return 1;
}
}
    }
